/* https://www.acmicpc.net/problem/1874 */
#include<stdio.h>
#include<stdlib.h>

int stack(int top);

char * ops;
int * inputs;	
int op_index=0,n,i_index,num=1, flag=0;

int main()
{
	int temp;
	scanf("%d", &n);
	ops = (char*)malloc(n*2);
	inputs = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &inputs[i]);	
	}	
	i_index = 0;
	stack(num);

	if(flag == 0)
	{
		for(int i=0;i<op_index;i++)
		{
			printf("%c\n", ops[i]);
		}
	}
	else
	{
		printf("NO\n");
	}

	free(inputs);
	return 0;
}

int stack(int top)
{
	while(op_index < n*2 + 1)
	{
		if (top > n + 1 )
		{
			flag=1;
			break;
		}
		if(i_index == n)
			break;
		if (*(inputs+i_index) >= top)
		{
			*(ops+op_index) = '+';
		 	op_index++;
		 	stack(++num);
		}
		else if (*(inputs + i_index) < top)
		{
		 	*(ops+op_index) = '-';
		 	op_index++;
		 	i_index++;
		 	break;
		}
	}
	return 0;
	
}