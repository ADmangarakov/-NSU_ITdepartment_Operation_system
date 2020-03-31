#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include "header.h"

int main (int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Enter program's name, which you want to execute\n");
        return EXIT_FAILURE;
    }

    pid_t process_id = fork();

    if (process_id == FORK_ERROR) {
        perror("Error fork:");
        return EXIT_FAILURE;
    }

    if (process_id == CHILD_ID) {
        execv(argv[1], &argv[1]);
        perror("Error exec:");
        return EXIT_FAILURE;
    }

    printf("Wait child: %d\n", process_id);

    int status = 0;
    process_id = wait(&status);
    if (process_id == FORK_ERROR) {
        perror("Error wait");
        return EXIT_FAILURE;
    }
    printf("Child process stop by exit, returns code: %d\n", WEXITSTATUS(status));
    return EXIT_SUCCESS;
}