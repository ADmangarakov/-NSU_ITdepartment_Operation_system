#include <stdio.h>
#include <stdlib.h>
#include "execvpe.h"

void destroyEnv(char **env) {
    for (int i = 0; i < COUNT_STRINGS; ++i) {
        free(env[i]);
    }
    free(env);
}


int initEnv(char ***env) {
    *env = (char **) calloc(COUNT_STRINGS, sizeof(char));
    if (*env == NULL) {
        return CALLOC_ERROR;
    }

    for (int i = 0; i < COUNT_STRINGS; ++i) {
        (*env)[i] = (char *) calloc(LENGTH_STRING, sizeof(char));

        if ((*env)[i] == NULL) {
            destroyEnv(*env);
            return CALLOC_ERROR;
        }
    }

    (*env)[0] = "FIRST=1";
    (*env)[1] = "NAME=child";
    (*env)[2] = "VARIABLE=TEST";
    (*env)[3] = NULL;

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Enter program's name, which you want to execute\n");
        return EXIT_FAILURE;
    }

    char **env = NULL;
    if(initEnv(&env) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    execvpe(argv[1], &argv[1], env);

    return EXIT_FAILURE;
}
