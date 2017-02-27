/* 이항 계수 3 : https://www.acmicpc.net/problem/11401 */
/* #메모이제이션#이항계수#역원#페르마의소정리 */
#include <cstdio>
#include <cstdlib>

#define divisor 1000000007

using namespace std;

long long mul(long long x, long long y, long long p) {
    long long ans = 1;
    while (y > 0) {
        if (y%2 != 0) {
            ans *= x;
            ans %= p;
        }
        x *= x;
        x %= p;
        y/=2;
    }
    return ans;
}

long long * factorials;

int main()
{
	int N,K;
	long long result, temp;
	scanf("%d%d", &N, &K);
	factorials= (long long *)calloc(N + 1, sizeof(long long));
	factorials[0] = 1; 
	for (int i = 1; i < N+1; ++i)
	{
		factorials[i] = (i*factorials[i-1])%divisor;
	}
	/*  */
	result = (factorials[N-K] * factorials[K]) % divisor;
	result = mul(result, divisor-2, divisor);
	result = result%divisor;
	result = factorials[N] * result;
	result = result%divisor;

	printf("%lld\n", result);
	free(factorials);
	return 0;
}