//
// Created by alex on 11.03.2020.
//

#ifndef LAB5_FILE_READER_H
#define LAB5_FILE_READER_H

#define BUF_SIZE 255
#define TABLE_SIZE 4
#define DECIMAL 10
#define ERROR_CODE -1
#define CONTINUE_CODE -1
#define BLOCK 1
#define TIME_OUT -2
#define NBLOCK 0

int create_table(const char *const file_name, int **table);
void print_string(char const *const FILE_NAME, int const *const table, long const str_num);
void get_str_num(long *const str_num, int const block_input);
#endif //LAB5_FILE_READER_H
