/* 이항 계수 2 : https://www.acmicpc.net/problem/11051 */
/* #메모이제이션#이항계수 */
#include <cstdio>
#include <cstdlib>

#define divisor 10007

using namespace std;


int ** memo;

int combination(int n, int k)
{
	if (memo[n][k] == 0)
	{

		memo[n][k] = (combination(n - 1, k - 1)%divisor + combination(n - 1, k)%divisor)%divisor;
	}	

	return memo[n][k]; 
}

int main()
{
	int N,K;
	int result;
	scanf("%d%d", &N, &K);
	memo = (int **) calloc(N + 1, sizeof(int *));
	for (int i = 0; i < N+1; ++i)
	{
		memo[i] = (int *) calloc(i+1, sizeof(int));
		memo[i][0] = 1;
		memo[i][i] = 1;
			
	}
	
	result = combination(N, K);
	result = result % 10007;
	printf("%d\n", result);
	

	for (int i = 0; i < N+1; ++i)
	{
		free(memo[i]);			
	}
	free(memo);
	return 0;
}