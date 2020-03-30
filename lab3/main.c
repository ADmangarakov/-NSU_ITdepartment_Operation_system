#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#include "header_lab3.h"

int main() {
    print_user_id();
    open_file();

    if ( setuid( geteuid() ) == ERROR_CODE ) {
        perror("Can't set user id");
        _exit(errno);
    }

    print_user_id();
    open_file();

    return 0;
}

void print_user_id() {

    printf("Your real id is: %u \n", getuid());
    printf("Your effective id is: %u \n", geteuid());
}

void open_file() {
    FILE* f = fopen("test.file", "r");

    if (f == NULL) {
        perror("Can't open file");
        _exit(errno);
    } else {
        printf("file opened successful!\n");
    }
}