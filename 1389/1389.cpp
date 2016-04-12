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
int Y;
int a[9]={1,2,6,24,120,720,5040,40320,362880};
//int b[20]={};
int f[1000100]={0};
int ANS=0x7fffffff;
int main()
{
    cin>>Y;
    for (int i=1;i<=1000000;++i)
        f[i]=0x7fffffff;
    f[0]=0;
    for (int j=0;j<=8;++j)
    {
        for (int i=1;i<=1000000;++i)
        {
            if (i-a[j]>=0)
            {
                f[i]=min(f[i-a[j]]+1,f[i]);
            }
        }
    }
    //cout<<f[362879]<<endl;
    //cout<<f[362880]<<endl;
    //cout<<f[362881]<<endl;
    //cout<<f[Y]<<endl;
    //cout<<f[1]<<endl;
    //cout<<f[24]<<endl;
    for (int i=Y;i<=1000000;++i)
    {
        ANS=min(f[i-Y]+f[i],ANS);
    }
    cout<<ANS<<endl;
    return 0;
}
