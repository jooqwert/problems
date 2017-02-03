#include<stdio.h>
#include<string.h>

int checkPS(int depth, char * str);
int checkSB(int depth, char * str);


int main()
{
	char buffer[32];
	fgets(buffer, sizeof(buffer)-1, stdin);

	for (int i = 0; i < strlen(buffer); ++i)
	{
		printf("%c", buffer[i]);
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

int checkSB(int depth, char * str)
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
