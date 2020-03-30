//
// Created by alex on 31.03.2020.
//

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "file_reader.h"

int create_table(const char *const ptr_file, int **table, int file_len) {

    int cur_str = 1, table_size_count = 1;
    for (int i = 0; i < file_len; ++i) {
        if (ptr_file[i] == '\n') {
            (*table)[cur_str] = i;
            ++cur_str;
        }
        if (cur_str == TABLE_SIZE * table_size_count) {
            ++table_size_count;
            *table = realloc(*table, table_size_count * TABLE_SIZE * sizeof(int));
        }
    }
    return cur_str;
}

long read_str_num_by_time(char *const line) {
    int fd, flags;

    if ((fd = open("/dev/tty", O_RDONLY | O_NDELAY)) == -1) {
        perror("/dev/tty");
        exit(2);
    }
    printf("Enter str number within five seconds:\n> ");
    sleep(5);
    if (read(fd, line, BUFSIZ) == 0) {
        line[0] = '-';
        line[1] = '2';
    }

    flags = fcntl(fd, F_GETFL);
    flags &= ~O_NDELAY; /* turn off delay flag */
    fcntl(fd, F_SETFL, flags);
    close(fd);
}

void get_str_num(long *const str_num, int const block_input) {
    char *line = malloc(BUFSIZ * sizeof(char));
    if (block_input) {
        read_str_num_by_time(line);
    } else {
        scanf("%s", line);
        if (ferror(stdin)) {
            perror("Error while reading str number:");
            exit(EXIT_FAILURE);
        }
    }

    char *endptr;
    errno = 0;
    *str_num = strtol(line, &endptr, DECIMAL);
    free(line);
    if (errno != 0) {
        perror("Bad input. Try again\n");
        *str_num = CONTINUE_CODE;
    }
    if (endptr == line) {
        fprintf(stderr, "No digits were found. Try again\n");
        *str_num = CONTINUE_CODE;
    }
}

void print_string(char const *const ptr_file, int const *const table, long const str_num) {
    long str_start_num = table[str_num - 1];
    long str_end_num = table[str_num];
    char *out_str = (char *) calloc(sizeof(char), (str_end_num - str_start_num + 1));
    strncpy(out_str, ptr_file + str_start_num, (str_end_num - str_start_num + 1));
    printf("%s\n", out_str);
    free(out_str);
}