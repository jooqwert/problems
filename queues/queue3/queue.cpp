/* 프린터 큐 : https://www.acmicpc.net/problem/1966 */
/* #queue#list#priority */

#include <stdio.h>
#include <queue>
#include <list>

using namespace std;
typedef struct document
{
	int id;
	int priority;
} document;

int main() {
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T;++i)
	{
		
		int n,m,index=0;
		scanf("%d%d", &n, &m);
		
		queue< document > q;
		list<int> l;
		for(int j=0; j<n;++j)
		{	
			document doc;
			scanf("%d", &doc.priority);
			doc.id = j;
			q.push(doc);
			l.push_back(doc.priority);
		}
		l.sort();
		l.reverse();

		while(!q.empty())
		{
			document doc = q.front();
			if(doc.priority >= l.front())
			{
				q.pop();
				l.pop_front();
				++index;
				if (doc.id == m)
				{
					printf("%d\n", index);
				}
			}
			else
			{
				q.pop();
				q.push(doc);
			}
		}
	}
	
	return 0;
}