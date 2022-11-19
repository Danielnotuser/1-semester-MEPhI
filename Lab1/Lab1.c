#include <stdio.h>

int inc_num(int n, int cnt)
{
	int res = n;
	for (int i = 1; i <= cnt - 1; i++)
		res = res * 10 + n;
	return res;
}

int poww(int cnt)
{
	int res = 1;
	for (int i = 1; i <= cnt; i++)
		res *= 10;
	return res;
}

int maxim(int a, int s)
{
	int res = 0, a1, n, cnt, leng = 0;
	for (int i = 0; i <= 9; i++)
	{
		a1 = a;
		cnt = 0;
		while (a1)
		{
			n = a1 % 10;
			if (n == i) cnt++;
			a1 /= 10;
		}
		if (cnt == 0) continue;
		if (s == 1) {
			res = inc_num(i, cnt) * poww(leng) + res;
			leng += cnt;
		}
		else res = res * poww(cnt) + inc_num(i, cnt);
	}
	return res * s;
}

int main()
{
	int a;
	printf("Write number: ");
	scanf("%d", &a);
	int s = 1;
	if (a < 0)
	{ 
		s = -1;
		a *= -1;
	}
	int res = maxim(a, s);
	printf("Maximum = %d", res);
	return 0;
}
