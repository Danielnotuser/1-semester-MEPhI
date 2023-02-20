#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "gen.h"

int main(int argc, char *argv[])
{
	char arg;
	int reversed = 0, opt = 0, num_arr = 0, num_elem = 0;
	char *field = NULL;
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
			fprintf(stderr, "Error! Too many required positional arguments.\n");
			free(field);
			return 1;
		}
		else
		{
			if (i == optind) num_elem = atoi(argv[i]);
			else num_arr = atoi(argv[i]);
		}
	}
	if (!num_arr || !num_elem)
	{
		fprintf(stderr, "Error! Missing one or two required positional arguments.\n");
		free(field);
		return 1;	
	}
	int (*cmp) (const Stud*, const Stud*);
	int err = choose_cmp(field, reversed, &cmp);
	if (err)
	{
		free(field);
		return 1;
	}
	srand(time(NULL));
	Stud *arr;
	clock_t start = 0, end = 0;
	double tm, sum_tm = 0;
	if (opt == 1)
	{
		for (int j = 0; j < num_arr; j++)
		{
			arr = (Stud*) calloc(num_elem, sizeof(Stud));
			for (int k = 0; k < num_elem; k++)
			{
				gen_stud(arr, k);
			}	
			start = clock();
			quick_sort(arr, 0, num_elem - 1, cmp);
			end = clock();
			tm = (double) (end - start) / CLOCKS_PER_SEC;
			sum_tm += tm;
			arr_free(&arr, num_elem);
		}
	}
	else if (opt == 2) 
	{
		for (int j = 0; j < num_arr; j++)
		{
			arr = (Stud*) calloc(num_elem, sizeof(Stud));
			for (int k = 0; k < num_elem; k++)
			{
				gen_stud(arr, k);
			}
			start = clock();
			shell_sort(arr, num_elem, cmp);
			end = clock();
			tm = (double) (end - start) / CLOCKS_PER_SEC;
			sum_tm += tm;
			arr_free(&arr, num_elem);
		}
	}
	else 
	{
		for (int j = 0; j < num_arr; j++)
		{
			arr = (Stud*) calloc(num_elem, sizeof(Stud));
			for (int k = 0; k < num_elem; k++)
			{
				gen_stud(arr, k);
			}
			start = clock();
			qsort(arr, num_elem, sizeof(Stud), (int (*) (const void *, const void *)) cmp);
			end = clock();
			tm = (double) (end - start) / CLOCKS_PER_SEC;
			sum_tm += tm;
			arr_free(&arr, num_elem);
		}
	}
	double res = (double) sum_tm /  num_arr;
	printf("Average time spent sorting an array of length %d = %.10lf\n", num_elem, res);
	free(field);
	return 0;
	
}
