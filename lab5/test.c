#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gen.h"

int main()
{
	int opt = 2, num_arr = 2, num_elem = 5;
	int (*cmp) (const Stud*, const Stud*) = stud_cmp_mark;
	srand(time(NULL));
	Stud *arr;
	clock_t start = 0, end = 0;
	double tm, sum_tm;
	if (opt == 2)
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
			tm = ((double) (end - start)) / CLOCKS_PER_SEC;
			sum_tm += tm;
			arr_free(&arr, num_elem);
		}
	}
	printf("time = %.10lf\n", (double) sum_tm / num_arr);
	return 0;
}
