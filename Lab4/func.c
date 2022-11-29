#include "func.h"

int str_leng(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i + 1);
}

void sep_str(char *str, char ***w, int *leng, char *last)
{
	char *word = NULL, **words = NULL;
	int i = 0, j = 0, k = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (!j)
				word = (char*) malloc(sizeof(char));
			word[j] = str[i];
			j++;
			word = (char*) realloc(word, (j + 1) * sizeof(char));
		}
		if ((word != NULL && (str[i] == ' ' || str[i] == '\t')) || str[i+1] == '\0')
		{
			word[j] = '\0';
			if (words)
				words = (char**) realloc(words, (k + 1) * sizeof(char*));
			else
				words = (char**) malloc(sizeof(char*));
			words[k] = word;
			(*last) = word[j - 1];
			word = NULL;
			j = 0;
			k++;
		}
		i++;
	} 
	(*leng) = k;
	(*w) = words;
}

void swap_strs(char **a, char **b)
{
	char *c;
	c = (*a);
	(*a) = (*b);
	(*b) = c;
}

void sort_words(char **words, int leng, char last)
{
	int cnt = 0, j;
	char *good;
	for (int i = 0; i < leng; i++)
	{
		if (words[i][0] == last)
		{
			good = words[i];
			for (j = i; j > cnt; j--)
				swap_strs(&words[j], &words[j - 1]);
			words[cnt] = good;
			cnt++;
		}
	}
}

void free_words(char ***w, int leng)
{
	for (int i = 0; i < leng; i++)
		free((*w)[i]);
	free(*w);
}
