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
using namespace std;
int XANS;
int N;
int a[110][110]={0};
const int dy[5]={0,0,1,0,-1};//shangyouxiazuo
const int dx[5]={0,-1,0,1,0};
bool v[110][110]={0};
//bool FLAG=0;
bool dfs(int x,int y,int mmih,int l)
{
    v[x][y]=true;
    if(x==N&&y==N)
        return true;
    bool flag=false;
    if(x<N&&!v[x+1][y]&&a[x+1][y]<=mmih+l&&a[x+1][y]>=mmih)
         flag|=dfs(x+1,y,mmih,l);
    if(x>1&&!v[x-1][y]&&a[x-1][y]<=mmih+l&&a[x-1][y]>=mmih)
         flag|=dfs(x-1,y,mmih,l);
    if(y>1&&!v[x][y-1]&&a[x][y-1]<=mmih+l&&a[x][y-1]>=mmih)
         flag|=dfs(x,y-1,mmih,l);
    if(y<N&&!v[x][y+1]&&a[x][y+1]<=mmih+l&&a[x][y+1]>=mmih)
         flag|=dfs(x,y+1,mmih,l);
    return flag;
}
bool doit(int mid)
{
    for(int i=max(a[1][1]-mid,0);i<=a[1][1];++i)
    {
        MSET(v,0);
        if(dfs(1,1,i,mid))
            return true;
    }
    return false;
}
int main()
{
    //RFF("1031.in");
    //WFF("1031.out");
    cin>>N;
    FOR(i,1,N)
        FOR(j,1,N)
            SCIa2(a,i,j);
    int l=0;
    int r=110;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (doit(mid))
        {
            XANS=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<XANS<<endl;
}
