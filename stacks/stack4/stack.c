/* https://www.acmicpc.net/problem/2504 */

#include<stdio.h>
#include<string.h>

void push(int * stack, int * i, int token);
int pop(int * stack, int * i);

int main()
{
	char buffer[32];
	int stack[64];
	int top = -1;
	int result = 0;
	fgets(buffer, sizeof(buffer)-1, stdin);
	printf("%d\n",strlen(buffer));
	for (int i = 0; i < strlen(buffer); ++i)
	{

		char token = buffer[i];

		if(token == '(' || token == '[')
		{
			push(stack, &top, -token);
		}
		else if (token == ')' && top > -1)
		{
			int tkn = -pop(stack, &top);
			int value = 0;

			while(tkn != '(')
			{
				int num = -tkn;
				if (num < 0 || tkn == 0)
				{
					printf("0\n");
					return 0;
				}
				value += num;
				tkn = -pop(stack, &top);
			}
			value = (value == 0 ? 1 : value);
			push(stack, &top, value * 2);
		}
		else if (token == ']' && top > -1)
		{
			int tkn= -pop(stack, &top);
			int value = 0;
		
			while(tkn != '[')
			{
				int num = -tkn;
				if (num < 0 || tkn == 0)
				{
					printf("0\n");
					return 0;
				}
				value += num;
				tkn = -pop(stack, &top);
			}

			value = (value == 0 ? 1 : value);
			push(stack, &top, value * 3);
		}
		else
		{
			printf("0\n");
			return 0;
		}
	}

	while(top != -1)
	{
		int temp = pop(stack, &top);
		if (temp < 0)
		{
			printf("0\n");
			return 0;
		}
		result+=temp;
	}
	printf("%d\n", result);
	return 0;
}

void push(int * stack, int * i, int token)
{
	if (token < 0)
	{
		printf("%c push \n", -token);
	}
	else
	{
		printf("%d push \n", token);
	}
	
	++*i;
	stack[*i] = token;
	
}
int pop(int * stack, int * i)
{
	if(*i < 0) return 0;
	int temp = stack[*i];
	if (temp < 0)
	{
		printf("%c pop \n", -temp);
	}
	else
	{
		printf("%d pop \n", temp);
	}

	--*i;
	return stack[*i + 1];
}