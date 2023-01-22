#ifndef MY_STRING
#define MY_STRING

#include <stddef.h>

size_t my_strlen(const char*);
char *my_strchr(const char *s, int c);
void *my_memcpy(void *restrict, const void *restrict, size_t);
char *read_str(const char*);
char *my_strdup(const char*);
char *my_strtok(char *restrict, const char *restrict);

#endif
