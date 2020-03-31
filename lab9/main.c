#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main() {
    pid_t pid;

    if ((pid = fork()) > 0) {
        wait(0);
        printf("Some text from parent\n");
    } else if (pid == 0) {
        system("cat long.txt");
    } else {
        perror("Error while make fork:");
        _exit(EXIT_FAILURE);
    }
    return 0;
}
