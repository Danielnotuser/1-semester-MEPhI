#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int insert_value(int **arr_old, int *leng, int ind, int val, int *memo)
{
	int *arr = *arr_old;
	(*leng)++;
	if (!arr)
	{
		arr = (int*) malloc(sizeof(int));
		arr[0] = val;
		*arr_old = arr;
		return 0;
	}
	if ((*leng) == (*memo)) 
	{
		(*memo) *= 2;
		arr = (int*) realloc(arr, *memo * sizeof(int));
	}
	for (int i = *leng - 1; i > ind; i--)
		arr[i] = arr[i-1];
	arr[ind] = val;
	*arr_old = arr;
	return 0;
}

int delete_by_index(int **arr_old, int *leng, int ind1, int ind2, int *memo)
{
	int diff = ind2 - ind1 + 1;
	int *arr = *arr_old;
	if (!arr) 
	{
		printf("Error! Array is empty.\n");
		return 2;
	}
	for (int i = ind1; i < *leng - diff; i++)
		arr[i] = arr[i + diff];
	(*leng) -= diff;
	if (*leng == 0)
	{
		*memo = 0;
		free(arr);
		arr = NULL;
	}
	else if ((*leng) < (*memo) / 2) 
	{
		while ((*leng) < (*memo) / 2)
			(*memo) /= 2;
		arr = (int*) realloc(arr, *memo * sizeof(int));
	}
	*arr_old = arr;
	return 0;
}

int find_dups(int **arr_old, int *leng, int *memo)
{
	int *arr;
	arr = *arr_old;
	int *arr_dups = (int*) malloc(*leng * sizeof(int));
	if (!arr) 
	{
		printf("Error! Array is empty.\n");
		return 2;
	}
	int dup = 0, ind1, i = 0, lendup = 0, j = 0;
	while (i < *leng)
	{
		if ((i < *leng - 1) && (arr[i] == arr[i+1]))
		{
			if (!dup) ind1 = i;
			arr_dups[j] = arr[i];
			j++;
			dup++;
		}
		else
		{
			if (dup)
			{
				arr_dups[j] = arr[i];
				delete_by_index(&arr, leng, ind1, i, memo);
				i = ind1 - 1;
				lendup += dup + 1;
				j++;
			}
			dup = 0;
		}
		i++;		
	}
	arr_dups = (int*) realloc(arr_dups, lendup * sizeof(int));
	printf("Array of duplicats:\n");
	print_array(arr_dups, lendup);
	free(arr_dups);
	*arr_old = arr;
	return 0;
}
