#include <stdio.h>
#include <math.h>

double ln_sum(double x, double eps, int *cnt)
{
	int i = 1;
	double y = x, res = x;
	double s = x;
	do
	{
		y *= x;
		i++;
		if (i % 4 != 0)
			s = y / i;
		else
			s = (-3) * y / i;
		res += s;
	} while (fabs(s) > eps);
	*cnt = i;
	return res;
	
}

int read_val(double *x, double *eps)
{
	double x1, eps1;
	int num;
	char end;
	while (1)
	{
		printf("Write x and epsilon: ");
		num = scanf("%lf %lf%c", &x1, &eps1, &end);
		if (num == -1)
		{
			printf("\nThe program was interrupted.");
			return 1;
		}
		if ((x1 <= -1) || (x1 > 1))
			printf("Error! x out of range. -1 < x <= 1\n");
		else if ((num != 3) || (end != '\n'))
			printf("Error! Types of entered values are wrong.\n");
		else
			break;
		scanf("%*[^\n]");
	}
	*x = x1;
	*eps = eps1;
	return 0;
}

int main()
{
	double x, eps;
	int cnt = 0;
	int bad = read_val(&x, &eps);
	if (bad)
	{
		return 1;
	}
	double res = ln_sum(x, eps, &cnt);
	double real = log(1 + x + x*x + x*x*x);
	printf("Actual answer = %.15lf\n", real);
	printf("Answer with algorithm = %.15lf, Number of iterations = %d", res, cnt);
	return 0;
}
