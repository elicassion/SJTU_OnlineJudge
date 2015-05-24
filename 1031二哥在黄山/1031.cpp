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
int ANS=0;
int N;
int a[110][110]={0};
const int dy[5]={0,0,1,0,-1};//shangyouxiazuo
const int dx[5]={0,-1,0,1,0};
bool v[110][110]={0};
bool FLAG=0;
void dfs(int x,int y,int ANS,int lMAX,int lMIN)
{
    //cout<<x<<' '<<y<<endl;
    if (x==N && y==N)
    {
        FLAG=1;
        return;
    }
    FOR(i,1,4)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx>=1 && nx<=N && ny>=1 && ny<=N && !v[nx][ny])
        {
            int MAX=max(lMAX,a[nx][ny]);
            int MIN=min(lMIN,a[nx][ny]);
            if (MAX-MIN<=ANS)
            {
                v[nx][ny]=1;
                dfs(nx,ny,ANS,MAX,MIN);
                v[nx][ny]=0;
            }
        }
    }
}
int main()
{
    RFF("1031.in");
    //WFF("1031.out");
    cin>>N;
    FOR(i,1,N)
        FOR(j,1,N)
            SCIa2(a,i,j);
    for(;;ANS++)
    {
        MSET(v,0);
        v[1][1]=1;
        int lMAX=max(a[1][1],a[N][N]);
        int lMIN=min(a[1][1],a[N][N]);
        dfs(1,1,ANS,lMAX,lMIN);
        if (FLAG)
        {
            cout<<ANS<<endl;
            return 0;
        }
    }
}
