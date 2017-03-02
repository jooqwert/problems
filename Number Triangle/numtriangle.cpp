/* 숫자삼각형 : https://www.acmicpc.net/problem/1932 */
/* #dp #동적프로그래밍 #기초 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int ** result = (int **) calloc(n, sizeof(int *));
	result[0] = (int *) calloc(1, sizeof(int));
	scanf("%d", &result[0][0]);

	for (int i = 1; i < n; ++i)
	{
		int temp;
		result[i] = (int *) calloc(i+1, sizeof(int));
		
		scanf("%d", &temp);
		result[i][0] = result[i-1][0] + temp;
		
		for (int j = 1; j < i; ++j)
		{
			scanf("%d", &temp);
			result[i][j] = max(result[i-1][j-1], result[i-1][j]) + temp;
		}

		scanf("%d", &temp);
		result[i][i] = result[i-1][i-1] + temp;
		

	}
	
	printf("%d\n", *(max_element(result[n-1], result[n-1] + n)));
	for (int i = 0; i < n; ++i)
	{
		free(result[i]);
	}
	free(result);
	return 0;
}