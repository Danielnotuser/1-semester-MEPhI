#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "stud.h"

int main(int argc, char *argv[])
{
	char arg;
	int reversed = 0, opt, nlen;
	char *field = NULL, *inp = NULL, *out = NULL;
	while ((arg = getopt(argc, argv, "s:rf:")) != -1)
	{
		switch (arg)
		{
			case 's': 
				if (!strcmp(optarg, "qsort")) {
					opt = 0;
					break;
				}
				else if (!strcmp(optarg, "quick")) {
					opt = 1;
					break;
				}
				else if (!strcmp(optarg, "shell")) {
					opt = 2;
					break;
				}
				else {
					fprintf(stderr, "Error! There is no \"%s\" sorting algorithm.\n", optarg);
					if (field) free(field); 
					return 1;
				}
			case 'r':
				reversed = 1;
				break;
			case 'f':
				field = strdup(optarg);
				break;
			case '?':
				if (field) free(field);
				fprintf(stderr, "Error! Unknown argument.\n");
				return 1;
		}
	}
	for (int i = optind; i < argc; i++)
	{
		if (i > optind + 1)
		{
			fprintf(stderr, "Error! Too many files in arguments.\n");
			free(inp);
			free(out);
			free(field);
			return 1;	
		}
		nlen = strlen(argv[i]);
		if (strcmp(argv[i] + nlen - 4, ".txt"))
		{
			fprintf(stderr, "Error! Incorrect name of file.\n");
			if (inp) free(inp);
			free(field);
			return 1;
		}
		else
		{
			if (i == optind) inp = strdup(argv[i]);
			else if (i == optind + 1) out = strdup(argv[i]);
		}
	}
	if (!inp || !out) 
	{
		fprintf(stderr, "Error! Missing one or two files.\n");
		if (inp) free(inp);
		free(field);
		return 1;
	}
	int (*cmp) (const Stud*, const Stud*);
	int err = choose_cmp(field, reversed, &cmp);
	if (err)
	{
		free(inp);
		free(out);
		free(field);
		return 1;
	}
	int len = 0;
	Stud *arr;
	read_file(&arr, inp, &len);
	printf("Input array: \n");
	arr_print(arr, len);
	if (opt == 1) quick_sort(arr, 0,  len - 1, cmp);
	if (opt == 2) shell_sort(arr, len, cmp);
	else qsort(arr, len, sizeof(Stud), (int (*) (const void *, const void *)) cmp);
	printf("Sorted array: \n");
	arr_print(arr, len);
	print_file(arr, out, len);
	arr_free(&arr, len);
	free(field);
	free(inp);
	free(out);
	return 0;
}
