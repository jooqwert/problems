/* https://www.acmicpc.net/problem/2504 */

#include<stdio.h>
#include<string.h>

int calculatePS(char * tokens, int depth);

int main()
{
	char buffer[32];
	fgets(buffer, sizeof(buffer)-1, stdin);
	printf("%d\n", calculatePS(buffer, 0));

	return 0;
}

int calculatePS(char * tokens, int depth)
{
	static int i = 0, isFalse = 0;

	int result = 0;

	while(tokens[i] != '\0')
	{
		int value;
		char rps, lps = tokens[i++];
		
		/* left parentheis check */
		if (lps == '(' ) /* Case of '(' */
		{

			value = tokens[i] == ')' ? 2 : 2*calculatePS(tokens, depth+1);
			rps = tokens[i++];

			/* Check parentheis pair */
			if (lps == '(' && rps == ')')
			{
				result += value;
			}
			else
			{
				isFalse = 1;
				break;
			}
 		}
		else if ( lps == '[' ) /* Case of '[' */
		{
			value = tokens[i] == ']' ? 3 : 3*calculatePS(tokens, depth+1);
			rps = tokens[i++];
			
			/* Check parentheis pair */
			if (lps == '['&& rps == ']')
			{
				result += value;
			}
			else
			{
				isFalse = 1;
				break;
			}
		}
		else
		{
			isFalse = 1;
			break;
		}

		/* Case of pop result */	
		if ((tokens[i] == ')'||tokens[i] == ']' ) && depth != 0) 
		{
			return result;
		}

	}

	return isFalse == 0 ? result : 0;
}