/* 조합 : https://www.acmicpc.net/problem/2407 */
/* #메모이제이션#조합#이항계수#biginteger */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const long long divisor = 1000000000000000000;
//const long long divisor = 100000;

typedef struct BigInt
{
	long long share;
	long long rest;
} BigInt;

BigInt *** memo;

BigInt * combination(int n, int k)
{
	if (memo[n][k]->share == 0 && memo[n][k]->rest == 0)
	{	
		memo[n][k]->share = combination(n - 1, k - 1)->share + combination(n - 1, k)->share;
		memo[n][k]->rest =  combination(n - 1, k - 1)->rest + combination(n - 1, k)->rest;
		if(memo[n][k]->rest >= divisor)
		{
			memo[n][k]->rest = memo[n][k]->rest - divisor;
			memo[n][k]->share = memo[n][k]->share + 1;
		}	
	}

	return memo[n][k]; 
}

int main()
{
	int N,K;
	BigInt * result;
	scanf("%d%d", &N, &K);
	memo = (BigInt ***) calloc(N + 1, sizeof(BigInt **));
	
	for (int i = 0; i < N+1; ++i)
	{
		memo[i] = (BigInt **) calloc(i+1, sizeof(BigInt*));
		for (int j = 0; j < i+1; ++j)
		{
			memo[i][j] = (BigInt *) calloc(1, sizeof(BigInt));
			memo[i][j]->share = 0;
			memo[i][j]->rest = 0;
		}
		memo[i][0]->rest = 1;
		memo[i][i]->rest = 1;
	}
	result = combination(N, K);
	if(result->share == 0)
		printf("%lld\n", result->rest);
	else
		printf("%lld%018lld\n", result->share, result->rest);
	
	for (int i = 0; i < N+1; ++i)
	{
		for (int j = 0; j < i+1; ++j)
		{
			free(memo[i][j]);
		}
		free(memo[i]);
	}
	free(memo);
	return 0;
}