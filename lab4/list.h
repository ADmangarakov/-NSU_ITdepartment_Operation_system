//
// Created by alex on 19.02.2020.
//

#ifndef LAB4_LIST_H
#define LAB4_LIST_H

#include <stdbool.h>

int static const BAD_ALLOC = 1;

typedef struct list list;

void init_list_node(list **node);

list *add_string(list *const cur_elem, char const *const string);

void print_list(list const *const head);

void revers_list(list **head);

#endif //LAB4_LIST_H
