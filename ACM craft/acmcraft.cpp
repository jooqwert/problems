/* ACM craft : https://www.acmicpc.net/problem/1005 */
/* #dp #동적프로그래밍 #기초 #위상정렬 #dfs */

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef struct building
{
	int cost;
	int total_cost;
} building;

int cal_cost(int n, int ** mat, building * buildings, int size)
{
	if (buildings[n].total_cost != 0)
	{
		return buildings[n].total_cost; 
	}

	int cost = buildings[n].cost;
	for (int i = 0; i < size; ++i)
	{
		int temp = buildings[n].cost;
		if(mat[n][i] == 1)
		{
			temp += cal_cost(i, mat, buildings, size);
		}

		if (cost < temp)
		{
			cost = temp;
		}
	}
	
	buildings[n].total_cost = cost;
	
	return cost;
}
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		int n, k, w;
		scanf("%d%d", &n,&k);

		building * buildings = (building *) calloc(n, sizeof(building));
		int ** mat = (int **) calloc(n, sizeof(int*));

		for (int j = 0; j < n; ++j)
		{
			int cost;
			scanf("%d", &cost);
			buildings[j].cost = cost;
			buildings[j].total_cost = 0;
			mat[j] = (int *) calloc(n, sizeof(int));
		}

		for (int j = 0; j < k; ++j)
		{
			int x,y;
			scanf("%d%d", &x, &y);
			mat[y-1][x-1] = 1;
		}

		scanf("%d", &w);

		printf("%d\n", cal_cost(w-1, mat, buildings, n));


		for (int j = 0; j < n; ++j)
		{	
			free(mat[j]);
		}
		free(mat);
		free(buildings);
	}

	return 0;
}