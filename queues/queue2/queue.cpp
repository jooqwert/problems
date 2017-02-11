/* DFS 와 BFS : https://www.acmicpc.net/problem/1260 */

#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void dfs(int vertex, vector< vector<bool> > &m);
void bfs(int vertex, vector< vector<bool> > &m);

int main(int argc, char const *argv[])
{
	int vcnt, ecnt, start_vertex;
	vector< vector<bool> > vmatrix;
	scanf("%d%d%d", &vcnt, &ecnt, &start_vertex);

	for ( int i = 0 ; i < vcnt; ++i )
	{
    	vector<bool> elem(vcnt, false);
    	vmatrix.push_back(elem);
    }
    
    for (int i = 0; i < ecnt; ++i)
    {
    	int row, col;
    	scanf("%d%d", &row, &col);
    	 /* connected undirected graph */
    	vmatrix[row-1][col-1] = true; 
    	vmatrix[col-1][row-1] = true;
    }


    dfs(start_vertex, vmatrix);
    printf("\n");
	bfs(start_vertex, vmatrix);
	return 0;
}




void dfs(int vertex, vector< vector<bool> > &m)
{
	static vector<bool> flags(m.size(), false);
	stack<int> s;
	
	s.push(vertex);
	flags[vertex - 1] = true;
	printf("%d ", vertex);

	while(!s.empty())
	{
		int v = s.top();
		bool isPrinted = false;
		for (int i = 0; i < m[v-1].size(); ++i)
		{	

			if (m[v-1][i] && !flags[i])
			{
				flags[i] = true;
				printf("%d ", i+1);
				s.push(i+1);
				isPrinted = true;
				break;
			}
		}
		if (!isPrinted)
			s.pop();
	}
	
	return;
}

 /* recursion */
/*void dfs(int vertex, vector< vector<bool> > &m)
{
	static vector<bool> flags(m.size(), false);
	vector<bool> arr = m[vertex - 1];
	
	flags[vertex - 1] = true;
	printf("%d ", vertex);


	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] && !flags[i])
		{
			dfs(i+1, m);
		}
	}
	return;
}
*/

void bfs(int vertex, vector< vector<bool> > &m)
{
	static vector<bool> flags(m.size(), false);
	queue<int> q;
	
	q.push(vertex);

	flags[vertex-1] = true;
	printf("%d ", vertex);
	
	while(q.size() > 0)
	{
		int v = q.front();
		q.pop();

		for (int i = 0; i < m[v-1].size(); ++i)
		{
			if (m[v-1][i] && !flags[i])
			{
				printf("%d ", i+1);
				q.push(i+1);
				flags[i] = true;
			}
		}
	}

	return;
}