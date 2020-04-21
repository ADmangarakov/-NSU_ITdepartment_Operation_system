//
// Created by alex on 20.04.2020.
//

#ifndef LAB17_HEADER_H
#define LAB17_HEADER_H

#include <stdlib.h>

#define ERROR -1
#define COUNT_SYMBS 1
#define STRING_LENGTH 40
#define NEW_LINE "\n"
#define TUNE "\7"

typedef int(*strHandler)(int terminal, char *string, size_t *lengthString, char c);

#endif //LAB17_HEADER_H
