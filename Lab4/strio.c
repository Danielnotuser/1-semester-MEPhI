#include "func.h"

void print_str(char **words, int leng)
{
	printf("\"");
	for (int i = 0; i < leng; i++)
	{
		if (i == leng - 1) printf("%s", words[i]);
		else printf("%s ", words[i]);
	}
	printf("\"\n");
}

int read_string(char ***w, int *leng_words, char *last)
{
	char *str, **words = NULL, end;
	int num, k = 0, leng;
	str = malloc(50 * sizeof(char));
	printf("Write string: ");
	num = scanf("%s%c", str, &end);
	while (num != -1)
	{
		leng = str_leng(str);
		str = (char*) realloc(str, leng * sizeof(char));
		if (words)
			words = (char**) realloc(words, (k + 1) * sizeof(char*));
		else
			words = (char**) malloc(sizeof(char*));
		words[k] = str;
		k++;
		if (end == '\n')
			break;
		str = NULL;
		str = malloc(50 * sizeof(char));
		num = scanf("%s%c", str, &end);
	}
	if (num == -1)
		return 1;
	(*w) = words;
	(*leng_words) = k;
	(*last) = str[leng - 2];
	return 0;
}

void parse_strs(int option)
{
	char *str, **words;
	int leng, bad = 0;
	char last;
	if (!option) 
	{
		str = readline("Write string: ");
		if (str == NULL) bad = 1;
	}
	else bad = read_string(&words, &leng, &last);
	while (!bad)
	{
		if (!option) sep_str(str, &words, &leng, &last);
		printf("Entered string: ");
		print_str(words, leng);
		sort_words(words, leng, last);
		printf("Sorted string: ");
		print_str(words, leng);
		free_words(&words, leng);
		if (!option) 
		{
			free(str);
			str = readline("Write string: ");
			if (str == NULL) bad = 1;
		}
		else bad = read_string(&words, &leng, &last);
	}
	printf("See you later!\n");
	if (!option) free(str);
}
