#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <string.h>
#include "header.h"

void printFileStatus(struct stat *status) {
    switch (status->st_mode & S_IFMT) { //musk for file type
        case S_IFREG: //if file
            printf("-");
            break;
        case S_IFDIR: //if dir
            printf("d");
            break;
        default:
            printf("?");
    };
}

void printAccess(struct stat *status) {
    static char symbRights[] = {'r', 'w', 'x'};
    static mode_t rights[] = {
            S_IRUSR, S_IWUSR, S_IXUSR,
            S_IRGRP, S_IWGRP, S_IXGRP,
            S_IROTH, S_IWOTH, S_IXOTH
    };

    char str[] = "---------";
    int count = sizeof(rights) / sizeof(mode_t);
    for(int i = 0; i < count; ++i) {
        if(status->st_mode & rights[i]) {
            str[i] = symbRights[i % COUNT_RIGHTS];
        }
    }

    printf("%s ", str);
}

int printUserInfo(struct stat *status) {
    struct passwd *userBuffer = getpwuid(status->st_uid);
    if (userBuffer == NULL) {
        perror("Error getpwuid");
        return EXIT_FAILURE;
    }
    printf(" %10s", userBuffer->pw_name);

    struct group *groupBuffer = getgrgid(status->st_gid);
    if (groupBuffer == NULL) {
        perror("Error getgrgid");
        return EXIT_FAILURE;
    }
    printf(" %10s", groupBuffer->gr_name);

    return EXIT_SUCCESS;
}

void printFileSize(struct stat *status) {
    if ((status->st_mode & S_IFMT) == S_IFREG) {
        printf(" %10d", status->st_size);
    } else {
        printf(" %10s", "");
    }
}

int printTimes(struct stat *status) {
    char *time = ctime(&status->st_mtime);
    if (time == NULL) {
        perror("Error ctime");
        return EXIT_FAILURE;
    }
    printf(" %.24s ", time);

    return EXIT_SUCCESS;
}

void printFilename(char *filepath) {
    size_t index = strlen(filepath) - 1;
    while (filepath[index] != '/' && index != 0) {
        --index;
    }

    if (index != 0) {
        ++index;
    }

    printf("%s", &filepath[index]);
}

int printInfo(char *file) {
    struct stat statBuffer;

    if (stat(file, &statBuffer) == ERROR) {
        perror("Error stat");
        return EXIT_FAILURE;
    }

    printFileStatus(&statBuffer);
    printAccess(&statBuffer);

    if(printUserInfo(&statBuffer) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    printFileSize(&statBuffer);

    if(printTimes(&statBuffer) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    printFilename(file);

    printf("\n");

    return EXIT_SUCCESS;
}


int main(int argc, char *argv[]) {

    if(argc <= 1) {
        return printInfo(".");
    }

    for (int i = 1; i < argc; ++i) {
        if(printInfo(argv[i]) != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
