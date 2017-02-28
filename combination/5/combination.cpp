/* 팩토리얼 0의 개수 : https://www.acmicpc.net/problem/1676 */
/* #팩토리얼#나머지#몫 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int N, factor = 5;
	int result = 0;
	scanf("%d", &N);

	int share = N/5;
	result +=share;
	while (share > 0)
	{
		share = share/5;
		result+=share;
	}
	
	printf("%d\n", result);
	return 0;
}