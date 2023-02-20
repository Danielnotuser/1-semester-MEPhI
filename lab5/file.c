#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stud.h"

int read_file(Stud **arr_init, char *inp, int *len)
{
	int n = 0;
	FILE *f = fopen(inp, "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error! Can't open file \"%s\"\n", inp);
		return 1;
	}
	fscanf(f, "%d%*c", &n);
	Stud *arr = (Stud*) calloc(n, sizeof(Stud));
	char *name; 
	char group[8];
	float mark;
	int pos;
	for (int i = 0; i < n; i++)
	{
		name = (char*) calloc(40, sizeof(char));
		pos = ftell(f);
		fscanf(f, "%[^,]%*c%*c", name);
		pos = ftell(f) - pos;
		name[pos - 2] = '\0';
		name = (char*) realloc(name, (pos - 1) * sizeof(char));
		arr[i].name = name;
		fscanf(f, "%7[^,]%*c%*c", group);
		memcpy(arr[i].group, group, 7);
		(arr[i].group)[7] = '\0';
		fscanf(f, "%f%*c", &mark);
		arr[i].mark = mark;
	}
	(*arr_init) = arr;
	(*len) = n;
	fclose(f);
	return 0;
}

int print_file(Stud *arr, char *out, int len)
{
	FILE *f = fopen(out, "w");
	for (int i = 0; i < len; i++)
		fprintf(f, "%s, %s, %f\n", arr[i].name, arr[i].group, arr[i].mark);
	fclose(f);
	return 0;
}
