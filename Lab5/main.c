#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "stud.h"

int main(int argc, char *argv[])
{
	char arg;
	int reversed = 0, opt, nlen;
	char *field, *inp, *out;
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
					return 1;
				}
			case 'r':
				reversed = 1;
				break;
			case 'f':
				field = strdup(optarg);
				break;
			case '?':
				fprintf(stderr, "Error! Unknown argument\n");
				return 1;
		}
	}
	printf("field = %s\n", field);
	for (int i = argc - 1; i >= argc - 2; i--)
	{
		nlen = strlen(argv[i]);
		printf("file = %s\n", argv[i]);
		if (strcmp(argv[i] + nlen - 4, ".txt"))
		{
			fprintf(stderr, "Error! Incorrect name of file.\n");
			return 1;
		}
		else
		{
			if (i == argc-1) out = strdup(argv[i]);
			else inp = strdup(argv[i]);
		}
	}
	int len = 0;
	Stud *arr;
	read_file(&arr, inp, &len);
	int (*cmp) (const Stud*, const Stud*);
	if (!strcmp(field, "name"))
	{
		if (reversed) cmp = stud_cmp_rname;
		else cmp = stud_cmp_name;
	}
	else if (!strcmp(field, "group"))
	{
		if (reversed) cmp = stud_cmp_rgroup;
		else cmp = stud_cmp_group;
	}
	else if (!strcmp(field, "mark")) 
	{
		if (reversed) cmp = stud_cmp_rmark;
		else cmp = stud_cmp_mark;
	}
	else
	{
		fprintf(stderr, "Error! There is no \"%s\" field.\n", field);
		return 1;
	}
	printf("len = %d\n", len);
	printf("Input: \n");
	arr_print(arr, len);
//	if (opt == 1) quick_sort(arr, len, cmp);
	if (opt == 2) shell_sort(arr, len, cmp);
	else qsort(arr, len, sizeof(Stud), (int (*) (const void *, const void *)) cmp);
	printf("Sorted array: \n");
	arr_print(arr, len);
	free(arr);
	free(inp);
	free(out);
	return 0;
}
