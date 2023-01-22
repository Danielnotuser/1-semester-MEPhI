#include <stdio.h>
#include "stud.h"

void quick_sort(Stud *s, int len, int (*compar) (const Stud*, const Stud*));

void shell_sort(Stud *s, int len, int (*compar) (const Stud*, const Stud*))
{
	for (int d = len / 2; d > 0; d /= 2)
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = i + d; j < len; j += d)
			{
				if (compar(&s[i], &s[j]) > 0)
					swap(&s[i], &s[j]);
			}
		}
	}
}
