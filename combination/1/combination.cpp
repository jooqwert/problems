/* 이항 계수 1 : https://www.acmicpc.net/problem/11050 */
/* #재귀#이항계수*/
#include <cstdio>

int factorial(int n)
{
	if (n==1 || n==0)
	{
		return 1;
	}
	return n*factorial(n-1);
}

int main()
{
	int N,K;
	scanf("%d%d", &N, &K);
	printf("%d\n", factorial(N)/(factorial(N-K)*factorial(K)));
	return 0;
}