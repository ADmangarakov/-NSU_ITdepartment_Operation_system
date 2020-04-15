//
// Created by alex on 31.03.2020.
//

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "execvpe.h"

extern char **environ;

int execvpe(const char *file, char *const argv[], char *envp[]) {
    char *path = getenv("PATH");
    if (path == NULL) {
        return EXEC_ERROR;
    }

    char dir[PATH_MAX] = {};
    int flag = FALSE;
    char *found = NULL;
    char *offset = path;
    int f = open(file, O_RDONLY);
    if (f != OPEN_ERROR){
        flag = TRUE;
        strcpy(dir, file);
        close(f);
    }
    while (flag != TRUE) {
        found = strstr(offset, ":");
        if (found == NULL) {
            return EXEC_ERROR;
        }
        strncpy(dir, offset, found - offset);
        dir[found - offset] = '\0';
        strcat(dir, "/");
        strcat(dir, file);

        f = open(dir, O_RDONLY);
        if (f != OPEN_ERROR) {
            flag = TRUE;
            close(f);
        }
        offset = found + 1;
    }

    environ = envp;
    execvp(dir, argv);
    perror("Error exec");
    return EXEC_ERROR;
}

