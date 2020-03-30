//
// Created by alex on 11.03.2020.
//

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>
#include "file_reader.h"

int create_table(const char *const file_name, int **table) {
    int file = open(file_name, O_RDWR);
    if (file == -1) {
        perror("Error while open file: ");
        exit(EXIT_FAILURE);
    }
    int file_len = lseek(file, 0, SEEK_END);
    char * ptr_file;
    ptr_file = (char *) mmap(0, file_len, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);


    char buf[BUF_SIZE];
    int real_len, cur_str = 1, count = 0, table_size_count = 1;
    do {
        real_len = read(file, buf, BUF_SIZE);
        for (int i = 0; i < real_len; ++i) {
            if (buf[i] == '\n') {
                (*table)[cur_str] = i + count * BUF_SIZE;
                ++cur_str;
            }
            if (cur_str == TABLE_SIZE * table_size_count) {
                ++table_size_count;
                *table = realloc(*table, table_size_count * TABLE_SIZE * sizeof(int));
            }
        }
        ++count;
    } while (real_len == BUF_SIZE);
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

void print_string(char const *const FILE_NAME, int const *const table, long const str_num) {
    long str_start_num = table[str_num - 1];
    long str_end_num = table[str_num];
    int file = open(FILE_NAME, O_RDONLY);
    if (file == -1) {
        perror("Error while open file: ");
        exit(EXIT_FAILURE);
    }
    if (lseek(file, str_start_num, SEEK_SET) == ERROR_CODE) {
        perror("Error while searching str:");
        close(file);
        exit(EXIT_FAILURE);
    }
    char *out_str = malloc(sizeof(char) * (str_end_num - str_start_num));
    if (read(file, out_str, str_end_num - str_start_num) == ERROR_CODE) {
        perror("Error while reading file:");
        close(file);
        exit(EXIT_FAILURE);
    }
    printf("%s\n", out_str);
    free(out_str);
    close(file);
}
