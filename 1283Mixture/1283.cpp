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
int N,M;
bool isL[1010][1010]={0};
int col[1010]={0};
int CL=1;
void ff(int p)
{
    int q[1010]={0};
    int h=1,t=2;
    q[1]=p;
    while (h!=t)
    {
        FOR(i,1,N)
        {
            if(isL[q[h]][i] && col[i]==0)
            {
                q[t++]=i;
                col[i]=CL;
            }
        }
        h++;
    }
}
int main()
{
    //RFF("1283.in");
    //WFF("t.out");
    scanf("%d %d",&N,&M);
    FOR(i,1,M)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        isL[a][b]=1;
        isL[b][a]=1;
    }
    FOR(i,1,N)
    {
        if (!col[i])
        {
            col[i]=CL;
            ff(i);
            CL++;
        }
    }
    CL--;
    int ans[1010]={0};
    ans[0]=1;
    ans[1]=1;
    FOR(i,1,N-CL)
    {
        int g=0;
        FOR(j,1,ans[0])
        {
            ans[j]=ans[j]*2+g;
            g=ans[j]/10;
            ans[j]%=10;
        }
        while(g!=0)
        {
            ans[++ans[0]]+=g;
            g/=10;
        }
    }
    RFOR(i,ans[0],1)
        printf("%d",ans[i]);
    return 0;
}
