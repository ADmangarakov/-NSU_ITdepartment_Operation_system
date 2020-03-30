//
// Created by alex on 19.02.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string_reader.h"

char *get_string(FILE *f) {
    char * buff = (char*)malloc(BUFF_SIZE * sizeof(char));
    fgets(buff, BUFF_SIZE, f);
    return buff;
}

int is_last_string(char const * const string) {
    return string[0] == '.';
}