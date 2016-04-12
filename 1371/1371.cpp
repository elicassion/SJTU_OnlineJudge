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
int p[100010];
int N,M;
int main()
{
    //RFF("1371.in");
    //WFF("t.out");
    scanf("%d %d",&N,&M);
    p[0]=0;
    FOR(i,1,N)
    {
        SCIa1(p,i);
    }
    FOR(i,N+1,100009)
        p[i]=0x7fffffff;
    sort(p+1,p+N+1);
    FOR(i,1,M)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int *l=lower_bound(p+1,p+N+1,x);
        int *r=upper_bound(p+1,p+N+1,y);
        printf("%d\n",r-l);
    }
    return 0;
}
