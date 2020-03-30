#include <stdio.h>
#include "list.h"
#include "string_reader.h"

int main() {
    struct list *strings;
    init_list_node(&strings);
    struct list *head = strings;
    char * buff;
    do {
        buff = get_string(stdin);
        strings = add_string(strings, buff);
    } while (!is_last_string(buff));
    revers_list(&head);
    print_list(head);
    return 0;
}
