//
// Created by alex on 31.03.2020.
//

#ifndef LAB7_FILE_READER_H
#define LAB7_FILE_READER_H

#define TABLE_SIZE 4
#define DECIMAL 10
#define CONTINUE_CODE -1
#define TIME_OUT -2
#define NBLOCK 0

int create_table(const char *const ptr_file, int **table, int file_len);
void print_string(char const *const ptr_file, int const *const table, long const str_num);
void get_str_num(long *const str_num, int const block_input);

#endif //LAB7_FILE_READER_H
