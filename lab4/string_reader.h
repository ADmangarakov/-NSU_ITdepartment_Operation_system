//
// Created by alex on 19.02.2020.
//

#ifndef LAB4_STRING_READER_H
#define LAB4_STRING_READER_H

#include <bits/types/FILE.h>

static int const BUFF_SIZE = 256;

char * get_string(FILE *f);

int is_last_string(char const * const string);

#endif //LAB4_STRING_READER_H
