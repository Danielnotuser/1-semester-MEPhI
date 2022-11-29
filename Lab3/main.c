#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
	int *arr = NULL;
	int n, bad, flag = 0;
	int leng = 0, memo = 0, ind = 0, val = 0;
	system("clear");
	printf("Hello! Select one of the menu items:\n");
	printf("    0 - to exit program\n");
	printf("    1 - to initialize array\n");
	printf("    2 - to insert value by index\n");
	printf("    3 - to delete value by index\n");
	printf("    4 - to delete same numbers standing in a row in the array\n");
	printf("    5 - to print the array\n");
	printf("    6 - to clear the window\n");
	printf("Write number (0-6): ");
	bad = read_val(&n);
	if (bad)
	{
		printf("\nInput has been interrupted.\n");
		printf("<---Goodbye!--->\n");
		return 1;
	}	
	while (n)
	{	
		switch (n)
		{
			case 1: 
				free(arr);
				flag = init_array(&arr, &leng, &memo); 
				break;
			case 2: 
				flag = input_insert(&ind, &val, leng);
				if (flag != 1)
					insert_value(&arr, &leng, ind, val, &memo); 
				break;
			case 3: 
				flag = input_delete(&ind, leng);
				if (flag != 1)
					delete_by_index(&arr, &leng, ind, ind, &memo); 
				break;
			case 4: 
				flag = find_dups(&arr, &leng, &memo); 
				break;
			case 5: 
				print_array(arr, leng); 
				break;
			case 6:
				system("clear");
				printf("Select one of the menu items:\n");
				printf("    0 - to exit program\n");
				printf("    1 - to initialize array\n");
				printf("    2 - to insert value by index\n");
				printf("    3 - to delete value by index\n");
				printf("    4 - to delete same numbers standing in a row in the array\n");
				printf("    5 - to print the array\n");
				printf("    6 - to clear the window\n");
				break;
			default: 
				printf("Error! You entered the number in the wrong range. 0 <= n <= 6\n");
		}
		if (flag == 1)
		{
			printf("\nInput has been interrupted.\n");
			break;
		}
		printf("Write number to continue (0-6): ");
		bad = read_val(&n);
		if (bad)
		{
			printf("\nInput has been interrupted.\n");				
			break;
		}	
	}
	free(arr);
	printf("<---Goodbye!--->\n");
	return 0;
}
