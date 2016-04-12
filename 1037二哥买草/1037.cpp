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
int N,M;
int high[10010];
int low[10010];
int CT;
int main()
{
    //RFF("1037.in");
    //WFF("t.out");
    scanf("%d %d",&N,&M);
    FOR(i,1,N)
        SCIa1(high,i);
    FOR(i,1,M)
        SCIa1(low,i);
    sort(high+1,high+N+1,greater<int>());
    sort(low+1,low+M+1,greater<int>());
    int pick_h=1;
    int pick_l=1;
    CT=N;
    while(pick_h<=N && pick_l<=M)
    {
        while (low[pick_l]>=high[pick_h])
        {
            ++pick_l;
            if (pick_l>M)
                break;
        }
        if (pick_l<=M)
        {
            ++CT;
            ++pick_l;
            ++pick_h;
        }
    }
    cout<<CT<<endl;
    return 0;
}
