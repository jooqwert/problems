/* 쉬운 계단 수 : https://www.acmicpc.net/problem/10844 */
/* #dp #동적프로그래밍 #기초 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	static int div = 1000000000;
	long long result = 0;
	scanf("%d", &n);
	
	int nums[2][10];
	
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j < 10; ++j)
			{
				nums[i%2][j] = 1;
			}
		}
		else
		{
			nums[i%2][0] = nums[(i-1)%2][1]%div;
			for (int j = 1; j < 9; ++j)
			{
				nums[i%2][j] = nums[(i-1)%2][j-1]%div + nums[(i-1)%2][j+1]%div;
				nums[i%2][j] %=div;
			}
			nums[i%2][9] = nums[(i-1)%2][8]%div;	
		}

	}


	for (int j = 1; j < 10; ++j)
	{
		result = (result%div + nums[(n-1)%2][j]%div)%div;
	}	
	printf("%lld\n", result);
	return 0;
}