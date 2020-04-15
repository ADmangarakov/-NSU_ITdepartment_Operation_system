//
// Created by alex on 31.03.2020.
//

#ifndef LAB11_EXECVPE_H
#define LAB11_EXECVPE_H

#define EXEC_ERROR -1
#define LENGTH_STRING 255
#define COUNT_STRINGS 4
#define CALLOC_ERROR -1
#define PATH_MAX 4096
#define OPEN_ERROR -1
#define FALSE 0
#define TRUE 1

int execvpe(const char *path, char *const argv[], char *envp[]);

#endif //LAB11_EXECVPE_H
