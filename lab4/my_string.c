#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_string.h"

size_t my_strlen(const char *s)
{
	size_t i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

void *my_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char *d = (char*) dest;
	char *s = (char*) src;
	for (size_t i = 0; i < n; i++)
		d[i] = s[i];
	return d;
}

char *read_str(const char* prompt)
{
	char buf[81];
	char *res = NULL;
	int n, buf_len, res_len, last_len = 0;
	printf("%s", prompt);
	do
	{
		n = scanf("%80[^\n]", buf);
		if (n < 0)
		{
			printf("\n");
			return NULL;
		}
		else if (n > 0)
		{
			buf_len = my_strlen(buf);
			res_len = last_len + buf_len;
			res = realloc(res, res_len + 1);
			my_memcpy(res + last_len, buf, buf_len);
			last_len = res_len;
		}
		else
			scanf("%*c");
	} while (n > 0);
	if (last_len > 0)
		res[last_len] = '\0';
	else
		res = calloc(1, sizeof(char));
	return res;
}

char *my_strdup(const char *s)
{
	int len = my_strlen(s);
	char *s1 = (char*) calloc(len + 1, sizeof(char));
	my_memcpy(s1, s, len);
	s1[len] = '\0';
	return s1;
}

char *my_strchr(const char *s, int c)
{
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return (char*) (s + i);
	return NULL;	
}

char *my_strtok(char *restrict s, const char *restrict delim)
{
	static char *str;
	if (s) str = s;	
	int word_len = 0;
	char *start;
	while (my_strchr(delim, *str))
		str++;
	start = str;
	if (*str == '\0')
		return NULL;
	while (!my_strchr(delim, *str) && *str != '\0')
	{
		word_len++;
		str++;
	}
	if (*str != '\0') str++;
	start[word_len] = '\0';
	return start;
}
