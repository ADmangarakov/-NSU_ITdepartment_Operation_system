#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include "header.h"

int main(int argc, char* argv[]) {
    FILE *fpout;
    char line[BUFSIZ];

    if((fpout = popen("./handler.a", "w")) == NULL) {
        perror("Error making pipe");
        return EXIT_FAILURE;
    }
    ssize_t code;
    char buffer;

    while((code = read(STDIN_FILENO, &buffer, sizeof(char))) > 0 && buffer != '\n') {
        if(fputc(buffer, fpout) == EOF) {
            perror("Write str in pipe error");
            pclose(fpout);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

