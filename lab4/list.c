//
// Created by alex on 19.02.2020.
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list {
    char *string;
    list *next;
};

void init_list_node(list **node) {
    *node = (list*)malloc(sizeof(list));
    if (*node == NULL) {
        fprintf(stderr, "Memory allocating error\n");
        exit(BAD_ALLOC);
    }
    (*node)->next = NULL;
    (*node)->string = NULL;
}

list* add_string(list * const cur_elem, char const * const string) {
    cur_elem->string = (char*)malloc((strlen(string)+1)*sizeof(char));
    strcpy(cur_elem->string, string);
    list *next;
    init_list_node(&next);
    cur_elem->next = next;
    return next;
}

void print_list(list const * const head) {
    list const * cur = head;
    while (cur != NULL) {
        printf("%s", cur->string);
        cur = cur->next;
    }
}

void revers_list(list ** head) {
    list * cur = *head;
    list * next = (*head)->next;
    list * prev = NULL;
    while (next != NULL) {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = cur->next;
    }
    *head = prev;
}


