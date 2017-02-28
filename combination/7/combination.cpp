/* 이항 쇼다운 : https://www.acmicpc.net/problem/6591 */
/* #재귀#이항계수*/
#include <cstdio>
#include <cstdlib>

using namespace std;


int ** memo;

int combination(int n, int k)
{
	if (memo[n][k] == 0)
	{

		memo[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
	}	

	return memo[n][k]; 
}


int main()
{
	int N,K;
	while(true)
	{
		scanf("%d%d", &N, &K);
		if (N==0&&K==0)
		{
			break;
		}
		if(K> N/2)
		{
			K=N-K;
		}
		memo = (int **) calloc(N + 1, sizeof(int *));
		for (int i = 0; i < N+1; ++i)
		{
			memo[i] = (int *) calloc(K+1, sizeof(int));
			memo[i][0] = 1;
			if (i<=K)
			{
				memo[i][i] = 1;
			}
		}
		printf("%d\n", combination(N, K));
		for (int i = 0; i < N+1; ++i)
		{
			free(memo[i]);			
		}
		free(memo);
	}
	return 0;
}
