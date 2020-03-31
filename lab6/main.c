#include <stdio.h>
#include <stdlib.h>
#include "file_reader.h"

int main() {
    char const *const FILE_NAME = "test.txt";
    int *table = calloc(TABLE_SIZE, sizeof(int));
    int max_str = create_table(FILE_NAME, &table);

    while (1) {
        long str_num;
        get_str_num(&str_num, NBLOCK); //BLOCK
        if (str_num == CONTINUE_CODE) continue;

        if (str_num == EXIT_SUCCESS) {
            printf("Program is closing\n");
            exit(EXIT_SUCCESS);
        } else if (str_num == TIME_OUT) {
            for (int i = 1; i < max_str; ++i) {
                print_string(FILE_NAME, table, i);
            }
            return EXIT_SUCCESS;
        } else if (str_num >= max_str || str_num < 1) {
            fprintf(stderr, "No such string! Try again\n");
            continue;
        }


        print_string(FILE_NAME, table, str_num);
    }
}



