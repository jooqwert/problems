/* 1로 만들기 : https://www.acmicpc.net/problem/1463 */
/* #dp #동적프로그래밍 #기초 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> v;
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
					

	for (int i = 3; i <= n; ++i)
	{
		int count1 = numeric_limits<int>::max();
		int count2 = v[i-1] + 1;
		if (i % 3 == 0)
		{
			count1 = v[i/3] + 1;
		}
		else if ( i % 2 == 0)
		{
			count1 = v[i/2] + 1;
		}

		int t = min(count1, count2);
		v.push_back(t);

	}

	printf("%d\n", v[n]);
	
	

	return 0;
}