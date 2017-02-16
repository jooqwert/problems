/* 조세퍼스 문제0 : https://www.acmicpc.net/problem/11866 */
/* #원형큐 */
#include <stdio.h>
#include <list>
#include <queue>
using namespace std;

int main()
{
	int N,M;
	scanf("%d%d", &N,&M);
	queue<int> q;
	for (int i = 0; i < N; ++i)
	{
		q.push(i+1);
	}

	printf("<");
	while(!q.empty())
	{
		for (int j = 1; j < M; ++j)
		{
			q.push(q.front());
			q.pop();  
		}
		printf("%d", q.front());
		q.pop();
		if (0 < q.size())
		{
			printf(", ");
		}
	}
	printf(">");

	return 0;
}








/* 조세퍼스 문제 0 : https://www.acmicpc.net/problem/11866 */
/* #반복자#iterator#원형#순환 */

/*
#include <stdio.h>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	int N,M;
	scanf("%d%d", &N,&M);
	list<int> permutation, result;
	list<int>::iterator iter;
	for (int i = 0; i < N; ++i)
	{
		permutation.push_back(i+1);
	}

	iter = permutation.begin();
	while(!permutation.empty())
	{
		for (int j = 1; j < M; ++j)
		{
			++iter;
			if (iter == permutation.end())
			{
				iter = permutation.begin();
			}  
		}
		result.push_back(*iter);
		iter = permutation.erase(iter);
		if (iter == permutation.end())
		{
			iter = permutation.begin();
		} 
	}

	list<int>::iterator i = result.begin();
	printf("<%d", *i);
	
	for (++i; i != result.end(); ++i)
	{
		printf(", %d", *i);
	}
	printf(">");

	return 0;
}
*/