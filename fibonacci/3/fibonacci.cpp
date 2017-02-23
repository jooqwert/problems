/* 피보나치 함수 : https://www.acmicpc.net/problem/1003 */
#include <cstdio>

static int zero_count, one_count;

int fibonacci(int n)
{
	if (n==0)
	{
		++zero_count;
		return 0;
	}
	else if (n==1)
	{
		++one_count;
		return 1;
	}
	else
	{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		int n;
		zero_count=0;
		one_count=0;
		scanf("%d", &n);
		fibonacci(n);
		printf("%d %d\n", zero_count, one_count);

	}
	

	return 0;
}