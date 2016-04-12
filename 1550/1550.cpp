#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
int N;
int sum = 0;
int q[10010];
int h = 1;
int t = 1;
string s;
int ht[10010];

void init()
{
	cin>>s;
	int cur = 0;
	int begin = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			string tmp = "";
			for (int j = begin + 1; j < i; ++j)
			{
				tmp += s[j];
			}
			ht[++cur] = atoi(tmp.c_str());
			begin = i;
		}
	}
}

int main()
{
	//scanf("%d", &N);
	q[0] = 0;
	cin>>N;
	//getchar();
	//getchar();
	init();
	for (int i = 1; i <= N; ++i)
	{
		int x = ht[i];
		//scanf("%d", &x);
		//getchar();
		if (h == t)
		{
			q[t++] = x;
		}
		else if (x >= q[h] && x > q[t-1])
		{
			for (int j = h; j < t; ++j)
			{
				sum += q[h] - q[j];
			}
			t = 2;
			h = 1;
			q[1] = x;
		}
		else if (x >= q[t-1] && x < q[h])
		{
			int j = t - 1;
			while (j > 0 && x > q[j])
			{
				--j;
			}
			for (int k = j + 1; k < t; ++k)
			{
				sum += x - q[k];
				q[k] = x;
			}
			q[t++] = x;
		}
		else if (x < q[h] && x < q[t-1])
		{
			q[t++] = x;
		}
	}
	printf("%d\n", sum);
	return 0;
}
