#include <iostream>
#include <cstdio>
using namespace std;
int N;
int stk_top = 0;
int stk[1000010];
int gp_num = 0;
int main()
{
	scanf("%d", &N);
	stk[0] = -1;
	for (int i = 0; i < N; ++i)
	{
		int x, p;
		scanf("%d %d", &p, &x);
		if (x >= stk[stk_top])
		{
			stk[++stk_top] = x;
		}
		else
		{
			//++gp_num;
			int cur = x;
			while (stk[stk_top] > cur)
			{
				--stk_top;
			}
			stk[++stk_top] = x;
		}
	}
	gp_num += stk_top;
	
	printf("%d\n", gp_num);
	return 0;
}