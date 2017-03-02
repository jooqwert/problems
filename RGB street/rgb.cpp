/* RGB 거리 : https://www.acmicpc.net/problem/10828 */
/* #dp #동적프로그래밍 #기초 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int L, result=0;
	scanf("%d", &L);

	int ** total_cost = (int **)calloc(L, sizeof(int *));
	total_cost[0] = (int *)calloc(3, sizeof(int));
	
	scanf("%d%d%d", &total_cost[0][0], &total_cost[0][1], &total_cost[0][2]);

	for (int i = 1; i < L; ++i)
	{
		int cost[3];
		total_cost[i] = (int *)calloc(3, sizeof(int));
		scanf("%d%d%d", &cost[0], &cost[1], &cost[2]);

		for (int j = 0; j < 3; ++j)
		{
			total_cost[i][j] = min(total_cost[i-1][(j+1)%3], total_cost[i-1][(j+2)%3]) + cost[j];  
		}

	}
	
	printf("%d\n", min(min(total_cost[L-1][0], total_cost[L-1][1]), total_cost[L-1][2]));


	return 0;
}