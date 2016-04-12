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
double f[1010][1010]={0};
const double pw=1.0/36;
int N;
int main()
{
    cin>>N;
    for (int i=1;i<=N;++i)
    {
        for (int j=1;j<=N;++j)
        {
            f[i][j]=1.0;
        }
    }
    FOR(i,1,N)
    {
        FOR(j,1,N)
        {
            for (int p=1;p<=6;++p)
            {
                for (int q=1;q<=6;++q)
                {
                    if (i-p>=1 && j-q>=1)
                    {
                        f[i][j]+=f[i-p][j-q]*pw;
                    }
                }
            }
        }
    }
    /*for (int i=1;i<=N;++i)
    {
        for (int j=1;j<=N;++j)
        {
            cout<<f[i][j]<<' ';
        }
        cout<<endl;
    }*/
    cout<<fixed<<setprecision(2)<<f[N][N]<<endl;
    return 0;
}
