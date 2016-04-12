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
int N,S;
int a[100310]={0};
int c[2000210]={0};
long long int ANS=0;
int main()
{
    //RFF("1382.in");
    scanf("%d %d",&N,&S);
    int maxn=-0x7fffffff;
    FOR(i,1,N)
    {
        scanf("%d",&a[i]);
        if (a[i]>maxn)
            maxn=a[i];
    }
    sort(a+1,a+1+N);
    c[max(maxn,S)+1]=N+1;
    for(int i=1;i<=N;++i)
        if(c[a[i]]==0) c[a[i]]=i;
    for(int i=max(S,maxn);i>=1;--i)
        if(c[i]==0) c[i]=c[i+1];
    int ub=c[S]-1;
    FOR(i,1,ub-1)
    {
        int tans=c[S-a[i]+1]-1-i;
        if (tans>0)
            ANS+=tans;
    }
    cout<<ANS<<endl;
}
