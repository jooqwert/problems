/* 피보나치 수 : https://www.acmicpc.net/problem/2747 */
/* #순차#순환 */

#include <cstdio>

int main(int argc, char const *argv[])
{
	int n;
	long int result, elems[3] = {0,1,1};
	scanf("%d", &n);
	if (n==0||n==1)
	{
		result = elems[n];
	}
	else
	{
		for (int i = 2; i <= n; ++i)
		{
			elems[i%3] = elems[(i-1)%3] + elems[(i-2)%3];
		}
		result = elems[n%3];	
	}
	printf("%ld\n", result);
	

	return 0;
}