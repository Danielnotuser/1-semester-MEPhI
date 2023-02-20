#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main()
{
	List *pref;
	printf("Write prefix: ");
	int n = read_str(&pref);
	if (n == -1) return 1;
	printf("Write string: ");
	List *str;
	n = read_str(&str);	
	while (n != -1)
	{
		printf("Entered string: ");
		if (str)
		{
			print_str(str);
			if (pref) add_prefix(pref, str);
			printf("Fixed string: ");
			print_str(str);
			free_list(&str);
		}
		else printf("\"\"\nFixed string: \"\"\n");
		printf("Write string: ");
		n = read_str(&str);
	}
	if (pref) free_list(&pref);
	printf("\nSee you next time!\n");
	return 0;
}
