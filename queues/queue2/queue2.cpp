/* DFS 와 BFS : https://www.acmicpc.net/problem/1260 */
/* 인접 리스트 사용 */

#include <stdio.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

void dfs(int vertex, vector< list<int> > &vl);
void bfs(int vertex, vector< list<int> > &vl);

int main(int argc, char const *argv[])
{
	int vcnt, ecnt, start_vertex;
	vector< list<int> > vlist;
	scanf("%d%d%d", &vcnt, &ecnt, &start_vertex);

	for ( int i = 0 ; i < vcnt; ++i )
	{
    	list<int> elem;
    	vlist.push_back(elem);
    }
    
    for (int i = 0; i < ecnt; ++i)
    {
    	int row, col;
    	scanf("%d%d", &row, &col);
    	vlist[row-1].push_front(col);
    	vlist[col-1].push_front(row); 
    }
 	for (int i = 0; i < vlist.size(); ++i)
    {
    	vlist[i].sort();
    	vlist[i].unique();
    }

    dfs(start_vertex, vlist);
    printf("\n");
	bfs(start_vertex, vlist);
	return 0;
}




void dfs(int vertex, vector< list<int> > &vl)
{
	static vector<bool> flags(vl.size(), false);
	stack<int> s;
	
	s.push(vertex);
	flags[vertex - 1] = true;
	printf("%d ", vertex);

	while(!s.empty())
	{
		list<int>::iterator iter;
		int v = s.top();
		bool isPrinted = false;

		for (iter = vl[v-1].begin(); iter != vl[v-1].end(); ++iter)
		{	
			int next_v = *iter; 
			if (!flags[next_v-1])
			{
				flags[next_v-1] = true;
				printf("%d ", next_v);
				s.push(next_v);
				isPrinted = true;
				break;
			}
		}
		if (!isPrinted)
			s.pop();
	}
	
	return;
}


void bfs(int vertex, vector< list<int> > &vl)
{
	static vector<bool> flags(vl.size(), false);
	queue<int> q;
	
	q.push(vertex);

	flags[vertex-1] = true;
	printf("%d ", vertex);
	
	while(q.size() > 0)
	{
		list<int>::iterator iter;
		int v = q.front();
		q.pop();

		for (iter = vl[v-1].begin(); iter != vl[v-1].end(); ++iter)
		{
			int next_v = *iter; 
			if (!flags[next_v-1])
			{
				printf("%d ", next_v);
				q.push(next_v);
				flags[next_v-1] = true;
			}
		}
	}

	return;
}