#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#ifndef FUNC_H
#define FUNC_H

int str_leng(char*);
void sep_str(char*, char***, int*, char*);
void swap_strs(char**, char**);
void sort_words(char**, int, char);
void free_words(char***, int);
void print_str(char**, int);
void parse_strs(int);

#endif
