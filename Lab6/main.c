#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main()
{
	List *pref;
	printf("Write prefix: ");
	int n = read_str(&pref);
	printf("prefix = ");
	print_str(pref);
	if (n == -1) return 1;
	printf("Write string: ");
	List *str;
	n = read_str(&str);	
	while (n != -1)
	{
		printf("Entered string: ");
		print_str(str);
		if (str->head) add_prefix(pref, str);
		printf("Fixed string: ");
		print_str(str);
		free_list(&str);
		str = list_init();
		printf("Write string: ");
		n = read_str(&str);
	}
	free_list(&pref);
	free(str);
	printf("\nSee you next time!\n");
	return 0;
}
