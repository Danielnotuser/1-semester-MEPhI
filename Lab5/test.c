#include <stdio.h>
#include <stdlib.h>
#include "stud.h"

int main()
{
	Stud *arr;
	int len;
	read_file(&arr, "input.txt", &len);
	arr_print(arr, len);
	return 0;
}
