#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_string.h"

#define DELIM " \t"
#define PROMPT "Write string: "

char *sort_str(const char*);
char last_char(char*, int);

int main()
{
	char *str = read_str(PROMPT);
	char *res;
	clock_t start = 0, end = 0;
	while (str)
	{
		printf("Entered string = \"%s\"\n", str);
		start = clock();
		res = sort_str(str);
		end = clock();
		printf("Sorted string = \"%s\"\n", res);
		printf("Program completed in %.10lf sec.\n", ((double) (end - start) / CLOCKS_PER_SEC));		free(str);
		free(res);
		str = read_str(PROMPT);
	}
	return 0;
}

char last_char(char *s, int s_len)
{
	char chr;
	for (int i = s_len - 1; i >= 0; i--)
	{
		if ((s[i] != ' ' && s[i] != '\t') && (i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t'))
		{
			chr = s[i];
			break;
		}
	}
	return chr;
}

char *sort_str(const char* str)
{
	char *s = my_strdup(str);
	int s_len = my_strlen(s);
	char *res = (char*) calloc(s_len + 1, sizeof(char));
	char *sort = (char*) calloc(s_len + 1, sizeof(char));
	char *def = (char*) calloc(s_len + 1, sizeof(char));
	int res_len = 0, sort_len = 0, word_len = 0, def_len = 0;
	char chr = last_char(s, s_len);
	char *word = my_strtok(s, DELIM);
	while (word != NULL)
	{
		word_len = my_strlen(word);
		if (word[word_len - 1] == chr)
		{
			my_memcpy(sort + sort_len, word, word_len);
			sort_len += word_len + 1;
			sort[sort_len - 1] = ' ';
		}
		else
		{
			my_memcpy(def + def_len, word, word_len);
			def_len += word_len + 1;
			def[def_len - 1] = ' ';
		}
		word = my_strtok(NULL, DELIM);
	}
	free(s);
	if (sort_len > 0 || def_len > 0) 
	{
		if (sort_len) my_memcpy(res, sort, sort_len);
		if (def_len) my_memcpy(res + sort_len, def, def_len - 1);
		res_len = sort_len + def_len - 1;
	}
	free(sort);
	free(def);
	res[res_len] = '\0';
	res = (char*) realloc(res, (res_len + 1) * sizeof(char));
	return res;
}
