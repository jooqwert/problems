#include<stdio.h>
#include<string.h>
int checkPS(int depth, char * str);

int main()
{
	int n;
	char buffer[64];
	scanf("%d", &n);
	fgets(buffer, sizeof(buffer)-1, stdin);

	for (int i = 0; i < n; ++i)
	{	
		fgets(buffer, sizeof(buffer)-1, stdin);
		switch (checkPS(0, buffer))
		{
			case 0 :
				printf("YES\n");
				break;
			case 1 :
				printf("NO\n");
				break;
		}
	}
	return 0;
}

int checkPS(int depth, char * str)
{
	if (depth<0)
	{
		return 1;
	}


	if (*str == '(')
	{
		return checkPS(depth + 1, str+1);
	} 
	else if (*str == ')')
	{
		return checkPS(depth - 1, str+1);
	}
	else
	{
		if (depth != 0)
			return 1;
	}
	return 0;

}