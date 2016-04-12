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
const int MAXN = 200010;
bool isL[MAXN]={0};
int fa[MAXN]={0};
int sons[MAXN]={0};
int N;
int ANS=1;
int main()
{
    //RFF("1045.in");
    //WFF("1045.out");
    isL[1]=1;
    scanf("%d",&N);
    getchar();
    for (int i=1;i<=N;++i)
    {
    	char opr;
    	opr=getchar();
    	if (opr == 'B')
    	{
    		int x,y;
    		scanf("%d %d",&x,&y);
    		isL[y]=1;
    		fa[y]=x;
    		++sons[x];
    	}
    	else
    	{
    		int x;
    		scanf("%d",&x);
    		isL[x]=0;
    		if (!isL[fa[x]])
    			ANS+=sons[x]-1;
    		else
    		{
    			ANS+=sons[x];
    			--sons[fa[x]];
    		}
    			
    		printf("%d\n",ANS);
    	}
    	getchar();
    }
    return 0;
}
