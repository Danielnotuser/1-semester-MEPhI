#include <stdio.h>
#include "stud.h"

void quick_sort(Stud *s, int left, int right, int (*compar) (const Stud*, const Stud*))
{
	int i = left, j = right;
	Stud x = s[(i + j) / 2];
	while (i <= j)
	{
		while (compar(&s[i], &x) < 0)
			i++;
		while (compar(&x, &s[j]) < 0)
			j--;
		if (i <= j)
		{
			swap(&s[i], &s[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		quick_sort(s, left, j, compar);
	else if (i < right)
		quick_sort(s, i, right, compar);
}

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
