/* AC : https://www.acmicpc.net/problem/5403 */
/* #덱 */
#include <cstdio>
#include <deque>
#include <queue>

using namespace std;

void removeEnter()
{
	char ch;
	while(((ch = getchar()) != '\n') && ch != EOF);
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	removeEnter();
	for (int i = 0; i < T; ++i)
	{
		deque<int> dq;
		queue<char> commands;
		int size;
		char ch;
		while((ch = getchar()) != '\n')
		{
			commands.push(ch);
		}
		scanf("%d", &size);

		removeEnter();
		getchar();
		for (int j = 0; j < size; ++j)
		{
			int temp;
			scanf("%d", &temp);
			dq.push_back(temp);
			getchar();
		}
		removeEnter();

		
		bool isReverse = false;
		while(!commands.empty())
		{
			char command = commands.front();
			if(command == 'R')
			{
				isReverse = !isReverse;
				commands.pop();
			}
			else if (command == 'D')
			{
				if (dq.empty())
				{
					printf("error\n");
					break;
				}

				if (isReverse)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}

				commands.pop();
			}
			else
			{
				commands.pop();
			}
		}
		if (commands.empty())
		{
			printf("[");
			if (isReverse && !dq.empty())
			{
				for (deque<int>::reverse_iterator riter = dq.rbegin(); riter != dq.rend() - 1; ++riter)
				{
	        		printf("%d,", *riter);
	    		}
	    		printf("%d", dq.front());
			}
			else if(!isReverse && !dq.empty())
			{
				for (deque<int>::iterator iter = dq.begin(); iter != dq.end() - 1; ++iter)
				{
	        		printf("%d,", *iter);
	    		}
	    		printf("%d", dq.back());
	   		}
			printf("]\n");
	    }
		
	}
	
	return 0;
}