/* 팩토리얼 : https://www.acmicpc.net/problem/10872 */
/* #팩토리얼 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int N;
	int result = 1;
	scanf("%d", &N);
	for (int i = 1; i < N+1; ++i)
	{
		result *=i;
	}
	printf("%d\n", result);
	return 0;
}