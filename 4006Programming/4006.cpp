#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<list>
#include<vector>
#include<set>
#include<map>
#define FOR(i,bg,ed) for(int i=bg;i<=ed;++i)
#define RFOR(i,bg,ed) for(int i=bg;i>=ed;--i)
#define FOR_S(i,bg,ed,step) for(int i=bg;i<=ed;i+=step)
#define RFOR_S(i,bg,ed,step) for(int i=bg;i>=ed;i-=step)
#define MSET(a,i) memset(a,i,sizeof(a))
#define CIa1(a,i) cin>>a[i]
#define CIa2(a,i,j) cin>>a[i][j]
#define COa1(a,i) cout<<a[i]<<' '
#define COa2(a,i,j) cout<<a[i][j]<<' '
#define SCIa1(a,i) scanf("%d",&a[i])
#define SCIa2(a,i,j) scanf("%d",&a[i][j])
#define SCOa1(a,i) printf("%d ",a[i])
#define SCOa2(a,i,j) printf("%d ",a[i][j])
#define RFF(s) freopen(s,"r",stdin)
#define WFF(s) freopen(s,"w",stdout)
#define LL long long int
#define SPACE printf(" ")
#define ENTER printf("\n")
using namespace std;
bool v[100010]={0};
struct problem{
    int tl;
    int pt;
};
problem p[100010];
int N;
long long int ANS=0;
int MAXT=-0x7fffffff;
bool cmp(problem a,problem b)
{
    return (a.pt>b.pt);
}
int main()
{
    //RFF("4006.in");
    //WFF("t.out");
    cin>>N;
    FOR(i,1,N)
    {
        cin>>p[i].tl;
        if (p[i].tl>MAXT)
            MAXT=p[i].tl;
    }
    FOR(i,1,N)
        cin>>p[i].pt;
    sort(p+1,p+N+1,cmp);
    RFOR(i,MAXT,1)
    {
        int cur=0;
		for (; cur<=N; ++cur)
		{
			if(p[cur].tl>=i && !v[cur])
				break;
		}
		if(cur<=N)
        {
			v[cur]=1;
			ANS+=p[cur].pt;
		}
    }
    cout<<ANS<<endl;
    return 0;
}
