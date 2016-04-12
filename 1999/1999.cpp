#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>
#define RFF(s) freopen(s,"r",stdin)
#define WFF(s) freopen(s,"w",stdout)
using namespace std;
int N,M;
int mp[110][110];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
bool v[110][110]={0};
int ANS=0x7fffffff;
int TC=0;
int Cx[10];
int Cy[10];
int dC[10][10];
struct node
{
	int x;
	int y;
	int stp;
};
int checkroad(int sx,int sy,int ex,int ey)
{
	int h=1;
	int t=2;
	q[1].x=sx;
	q[1].y=sy;
	q[1].stp=0;
	node q[100010];
	while (h!=t)
	{
		for(int i=0;i<=3;++i)
		{
			int tx=q[h].x+dx[i];
			int ty=q[h].y+dy[i];
			if (tx>=1&&tx<=N && ty>=1&&ty<=M)
			{
				if (tx==ex && ty==ey)
				{
					return q[h].stp+1;
				}
				else if (mp[tx][ty]==0 || mp[tx][ty]==1)
				{
					q[t].x=tx;
					q[t].y=ty;
					q[t].stp=q[h].stp+1;
					++t;
					if (t>=1000000)
						t=1;
				}
			}
		}
		++h;
		if (h>=100000)
			h=1;
	}
	return -1;
}
int main()
{
    //RFF("1999.in");
    //WFF("1999.out");
	scanf("%d %d",&N,&M);
	for (int i=1; i<=N; ++i)
	{
		for (int j=1; j<=M; ++j)
		{
			scanf("%d",&mp[i][j]);
			if (mp[i][j]==2)
			{
				Cx[0]=i;
				Cy[0]=j;
			}
			if (mp[i][j]==1)
			{
				++TC;
				Cx[TC]=i;
				Cy[TC]=j;
			}
		}
	}
	for (int i=0;i<=TC;++i)
	{
		for (int j=i+1;j<=TC;++j)
		{
			dC[i][j] = checkroad(Cx[i],Cy[i],Cx[j],Cy[j]);
			dC[j][i] = dC[i][j];
		}
	}
	
    return 0;
}
