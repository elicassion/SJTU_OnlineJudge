#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char src[110];
//char res[110];
char mark[110];
int main()
{
	while (gets(src))
	{
		int stk[110];
		int stk_top = 0;
		int src_l = strlen(src);
		for (int i = 0; i < src_l; ++i)
		{
			if (src[i] == '(')
			{
				stk[++stk_top] = i;
				mark[i] = ' ';
			}
			else if (src[i] == ')')
			{
				if (stk_top == 0)
				{
					mark[i] = '?';
				}
				else
				{
					--stk_top;
					mark[i] = ' ';
				}
			}
			else
			{
				mark[i] = ' ';
			}
		}
		while (stk_top)
		{
			mark[stk[stk_top--]] = '$';
		}
		puts(src);
		puts(mark);
		puts("\n");
	}
}