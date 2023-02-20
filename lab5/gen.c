#include <stdio.h>
#include <stdlib.h>
#include "gen.h"

char *gen_name()
{
	int len = rand() % 40 + 10;	
	char *name = (char*) calloc(len + 1, sizeof(char));
	name[0] = rand() % 26 + 65;
	for (int i = 1; i < len; i++)
		name[i] = rand() % 26 + 97;
	name[len] = '\0';
	return name;
}

void gen_group(char group[8])
{
	int first = rand() % 4;
	switch (first)
	{
		case 0: group[0] = 'B'; break; // form of education
		case 1: group[0] = 'S'; break;
		case 2: group[0] = 'M'; break;
		case 3: group[0] = 'A'; break;
	}
	for (int i = 1; i < 7; i++)
	{
		if (i == 3) {
			group[i] = '-';
			continue;
		} 
		if (i == 4) {
			group[i] = rand() % 9 + 49; // num of institute
		}
		group[i] = rand() % 10 + 48;
	}
	group[7] = '\0';
}

void gen_stud(Stud *arr, int ind)
{
	arr[ind].name = gen_name();
	gen_group(arr[ind].group);
	arr[ind].mark = (float) rand() / RAND_MAX * 100.0;
}
