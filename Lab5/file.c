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
	for (int i = 0; i < n; i++)
	{
		name = (char*) calloc(40, sizeof(char));
		fscanf(f, "%[^,]%*c%*c", name);
		*strchr(name, ',') = '\0';
		name = (char*) realloc(name, strlen(name) * sizeof(char));
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
