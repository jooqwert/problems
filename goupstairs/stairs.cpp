/* 계단 오르기 : https://www.acmicpc.net/problem/2579 */
/* #dp #동적프로그래밍 #기초 */

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int ** t_score = (int **) calloc(n, sizeof(int *));

	for (int i = 0; i < n; ++i)
	{
		int score;
		scanf("%d", &score);
		t_score[i] = (int *) calloc(2, sizeof(int));
		/* i 번째로 0 : 첫 번째 계단 시작 1 : 두번째 계단 시작 */
		if (i==0)
		{
			t_score[i][0] = score;
		}
		else if (i==1) 
		{
			t_score[i][1] = t_score[i-1][0] + score;
			t_score[i][0] = score;
		}
		else if(i > 1)
		{
			t_score[i][0] = max(t_score[i-2][0], t_score[i-2][1]) + score;
			t_score[i][1] = t_score[i-1][0] + score;
		}


	}
	
	printf("%d\n", max(t_score[n-1][0], t_score[n-1][1]));
	
	for (int i = 0; i < n; ++i)
	{
		free(t_score[i]);
	}
	free(t_score);

	return 0;
}