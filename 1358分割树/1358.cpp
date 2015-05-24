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
int N;
int ans[110000];
int f[110000]={};
int nt[110000];
int t[110000];
int CT=0;
int sons(int v,int father)
{
    int sum=1;
    int tempsum;
    bool flag=true;
    for (long e=f[v]; e!=0; e=nt[e])
    {
		if (t[e]==father)
            continue;
		tempsum=(sons(t[e],v));
		sum+=tempsum;
		flag=flag && (tempsum<=N/2);
	}
	flag=flag && (N-sum<=N/2);
	if (flag)
    {
		++CT;
		ans[CT]=v;
	}
	return sum;
}
int main()
{
    //RFF("1358.in");
    //WFF("t.out");
    scanf("%d",&N);
    FOR(i,1,N-1)
    {
		int x,y;
		scanf("%d %d",&x,&y);
		t[i]=y;
		nt[i]=f[x];
		f[x]=i;

		t[2*N-i]=x;
		nt[2*N-i]=f[y];
		f[y]=2*N-i;
	}
	sons(1,0);
	sort(ans+1,ans+1+CT);
	FOR(i,1,CT)
    {
        SCOa1(ans,i);
        ENTER;
    }
	return 0;
}
