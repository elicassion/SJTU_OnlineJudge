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
#define FOR(i,bg,ed) for(int i=bg;i<=ed;++i)
#define RFOR(i,bg,ed) for(int i=bg;i>=ed;--i)
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
using namespace std;
int N;
int a,b;
int p[610][610];
void prt_hri()
{
    FOR(i,1,a)
    {
        RFOR(j,a,1)
            SCOa2(p,i,j);
        printf("\n");
    }
}
void prt_ver()
{
    RFOR(i,a,1)
    {
        FOR(j,1,a)
            SCOa2(p,i,j);
        printf("\n");
    }
}
void prt_dia()
{
    FOR(i,1,a)
    {
        FOR(j,1,a)
            SCOa2(p,j,i)<<' ';
        printf("\n");
    }
}
void doit()
{
    scanf("%d %d",&a,&b);
    FOR(i,1,a)
        FOR(j,1,a)
            SCIa2(p,i,j);
    if (b==0)
        prt_hri();
    else if (b==1)
        prt_ver();
    else
        prt_dia();
}
int main()
{
    //RFF("1023.in");
    //WFF("t.out");
    scanf("%d",&N);
    FOR(i,1,N)
    {
        doit();
    }
    return 0;
}
