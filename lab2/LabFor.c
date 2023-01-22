#include <stdio.h>
#include <math.h>

double ln_sum(double x, int n)
{
	double y = x, res = x;
	for (int i = 2; i <= n; i++)
	{
		y *= x;
		if (i % 4 != 0)
			res += y / i;
		else
			res += (-3) * y / i;
	}	
	return res;
}

int read_val(double *x, int *n)
{
	double x1;
	int n1, num;
	char end;
	while (1)
	{
		printf("Write x and number of iterations: ");
		num = scanf("%lf %d%c", &x1, &n1, &end);
		if (num == -1)
		{
			printf("\nThe program was interrupted.");
			return 1;
		}
		else if ((x1 <= -1) || (x1 > 1))
			printf("Error! x out of range. -1 < x <= 1\n");
		else if ((num != 3) || (end != '\n'))
			printf("Error! Types of entered values are wrong.\n");
		else
			break;
			
		scanf("%*[^\n]");	
	}
	*x = x1;
	*n = n1;
	return 0;
}

int main()
{
	double x;
	int n;
	int bad = read_val(&x, &n);
	if (!bad) 
	{
		double res = ln_sum(x, n);
		double real = log(1 + x + x*x + x*x*x);
		printf("Actual answer: %.15lf\n", real);
		printf("Answer with algorithm: %.15lf", res);
	}
	return 0;	
}
