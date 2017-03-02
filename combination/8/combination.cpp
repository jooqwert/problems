/* 이항 쇼다운 : https://www.acmicpc.net/problem/6591 */
/* #이항계수 #메모리 #최소화 #팩토리얼 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	long long N,K, result;
	while(true)
	{
		scanf("%lld%lld", &N, &K);
		if (N==0&&K==0)
		{
			break;
		}
		
		if(K > N/2)
		{
			K=N-K;
		}
	
		result = 1;
		long long * k = (long long *) calloc (K, sizeof(long long));
		for (long long i = 0; i < K; ++i)
		{
			k[i] = i+1;
		} 

		for (long long i = N; i > N-K; --i)
		{

			result = result * i;

			for (long long j = 0; j < K; ++j)
			{
				if (k[j] !=0 && result % k[j] == 0)
				{
					result = result / k[j];
					k[j] = 0;
				}
			} 


		}

		printf("%lld\n", result);
	}
	return 0;
}
