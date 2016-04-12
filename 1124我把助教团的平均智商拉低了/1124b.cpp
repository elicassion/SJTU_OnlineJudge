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
int IEQ,IIQ,N;
int EQ[500],IQ[500];
int maxQ=-0x7fffffff;
int f[402][32100]={0};
int main()
{
    //RFF("1124.in");
    cin>>N;
    cin>>IEQ>>IIQ;
    FOR(i,1,N)
    {
        cin>>EQ[i]>>IQ[i];
    }
    if (IEQ<0)
    {
        cout<<"Death"<<endl;
        return 0;
    }
    memset(f,-50000,sizeof(f));
    f[0][IEQ]=IIQ;
    FOR(i,1,N)
    {
        FOR(j,0,31000)
        {
            if (j-EQ[i]>=0 && f[i-1][j-EQ[i]]>-50000)
                    f[i][j]=max(f[i-1][j-EQ[i]]+IQ[i],f[i-1][j]);
            else
                f[i][j]=f[i-1][j];
                //cout<<"f"<<i<<' '<<j<<": "<<f[i][j]<<endl;
        }
    }
    FOR(j,1,31000)
    {
        if (f[N][j] > 70 && f[N][j] * j>maxQ)
            maxQ = f[N][j] * j;
    }
    if (f[0][IEQ] * IEQ >maxQ)
        maxQ = f[0][IEQ] * IEQ;
    if (maxQ>0)
        cout<<maxQ<<endl;
    else
        cout<<"Death"<<endl;
    return 0;
}
