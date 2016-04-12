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
int T;
int N,M;
int mp[1010][1010];
bool v[1010][1010];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
struct node
{
	int x;
	int y;
	int stp;
};
bool doit()
{
	stack<node> s;
	node st ;
	st.x=1; st.y=1; st.stp=0;
	s.push(st);
	v[1][1]=1;
	while(!s.empty())
	{
		node cur = s.top();
		s.pop();
		for (int i=0;i<=3;++i)
		{
			int tx = cur.x+dx[i];
			int ty = cur.y+dy[i];
			int tstp = cur.stp+mp[tx][ty];
			if (tx>=1&&tx<=N && ty>=1&&ty<=M)
			{
				if (!v[tx][ty] && tstp<=1)
				{
					v[tx][ty]=1;
					node nxt;
					nxt.x=tx;nxt.y=ty;nxt.stp=tstp;
					s.push(nxt);
					if (tx==N&&ty==M)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main()
{
    //RFF("2202.in");
    //WFF("2202.out");
    scanf("%d",&T);
    for (int ti=1;ti<=T;++ti)
    {
	    memset(v,0,sizeof(v));
	    scanf("%d %d",&N,&M);
		for (int i=1; i<=N; ++i)
		{
			for (int j=1; j<=M; ++j)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		if (doit())
			cout<<1<<endl;
		else
			cout<<0<<endl;
    }
    return 0;
}
