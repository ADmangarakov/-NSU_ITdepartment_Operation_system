//
// Created by User on 029 29.04.20.
//

#ifndef LAB20_UTIL_H
#define LAB20_UTIL_H
#include <stdlib.h>

void * checkMalloc(size_t size);
int extendStr(char **str, size_t *length);
int addChar(char **str, size_t *length, size_t *pos, char c);

#endif //LAB20_UTIL_H
