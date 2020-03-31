#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <bits/fcntl-linux.h>
#include <unistd.h>
#include <sys/mman.h>
#include "file_reader.h"

int main() {
    char const *const FILE_NAME = "../main.c";
    int *table = calloc(TABLE_SIZE, sizeof(int));

    int file = open(FILE_NAME, O_RDWR);
    if (file == -1) {
        perror("Error while open file: ");
        exit(EXIT_FAILURE);
    }
    int file_len = lseek(file, 0, SEEK_END);
    char *ptr_file;
    ptr_file = (char *) mmap(0, file_len, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);

    int max_str = create_table(ptr_file, &table, file_len);

    while (1) {
        long str_num;
        get_str_num(&str_num, NBLOCK); //BLOCK
        if (str_num == CONTINUE_CODE) continue;

        if (str_num == EXIT_SUCCESS) {
            printf("Program is closing\n");
            close(file);
            munmap(ptr_file, file_len);
            return EXIT_SUCCESS;
        } else if (str_num == TIME_OUT) {
            for (int i = 1; i < max_str; ++i) {
                print_string(FILE_NAME, table, i);
            }
            close(file);
            munmap(ptr_file, file_len);
            return EXIT_SUCCESS;
        } else if (str_num >= max_str || str_num < 1) {
            fprintf(stderr, "No such string! Try again\n");
            continue;
        }
        print_string(ptr_file, table, str_num);
    }
}


