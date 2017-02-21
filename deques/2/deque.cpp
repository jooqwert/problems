/* 회전하는 큐 : https://www.acmicpc.net/problem/1021 */
/* #덱#순환*/
#include <stdio.h>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M, result=0;
	deque<int> dq;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; ++i)
	{
		dq.push_back(i+1);
	}

	for (int i = 0; i < M; ++i)
	{
		int num, front;
		scanf("%d", &num);
		front = dq.front();
		if (front == num)
		{
			dq.pop_front();
		}
		else
		{	int cnt = 0;
			while(front != num)
			{
				dq.push_back(front);
				dq.pop_front();
				front = dq.front();
				++cnt;
			}
			result+= dq.size() - cnt > cnt ? cnt : dq.size() - cnt;
		}
	}
	printf("%d\n", result);

	return 0;
}