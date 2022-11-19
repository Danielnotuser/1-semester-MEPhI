#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void print_array(int *arr, int leng)
{
	if (!arr) 
		printf("Error! Array is empty.\n");
	else
	{
		printf("Array = ");
		for (int i = 0; i < leng; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}

int read_val(int *x)
{
	int num;
	char end;
	do
	{
		num = scanf("%d%c", x, &end);
		if (num == -1)
			return 1;
		if ((num == 2) && (end == '\n'))
			return 0;
		printf("Error! Type of entered value is wrong.\n");
		printf("Write number again: ");
		scanf("%*[^\n]");
	} while ((num != 2) || (end != '\n'));
	return 0;
}

int read_ind(int *ind)
{
	int bad;
	do
	{
		bad = read_val(ind);
		if (bad)
			return 1;
		if (*ind < 0)
			printf("Error! Entered index below zero. Try again...\n");
		else
			return 0;
		printf("Write index again: ");
	} while (1);
}

int init_array(int **arr_old, int *leng, int *memo)
{
	int *arr = NULL, bad;
	do
	{
		printf("Write number of elements: ");
		bad = read_val(leng);
		if (bad)
			return 1;
		(*memo) = (*leng) * 2;
		arr = (int*) malloc(*memo * sizeof(int));
		if (!arr) printf("Memory allocation failed. Try again...\n");
	} while(!arr);
	printf("Write elements of the array: \n");
	for (int i = 0; i < *leng; i++)
	{
		printf("arr[%d] = ", i);
		bad = read_val(&arr[i]);
		if (bad)
			return 1;
	}
	*arr_old = arr;
	return 0;
}

int input_insert(int *ind, int *val, int leng)
{
	int bad;
	printf("Write index of inserted value: ");
	bad = read_ind(ind);
	if (bad)
		return 1;
	else if (*ind >= leng) *ind = leng;
	printf("Write inserted value: ");
	bad = read_val(val);
	if (bad)
		return 1;
	return 0;
}

int input_delete(int *ind, int leng)
{
	int bad;
	do
	{
		printf("Write index of deleted value: ");
		bad = read_ind(ind);
		if (bad) 
			return 1;
		if (*ind >= leng)
			printf("Error! Index out of range. 0 <= index <= %d. Try again...\n", leng - 1);
		else
			return 0;
	} while (1);
	return 0;
}
