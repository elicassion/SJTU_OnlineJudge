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
int a[9][9];
bool vx[10][10]={0};
bool vy[10][10]={0};
bool vk[10][10]={0};
int T;
const int dx[9]={0,0,-1,-1,-1,0,1,1,1};
const int dy[9]={0,-1,-1,0,1,1,1,0,-1};
const int cx[9]={0,0,-3,-3,-3,0,3,3,3};
const int cy[9]={0,-3,-3,0,3,3,3,0,-3};
int ANS=0;
int getk(int x,int y)
{
    return (x/3)*3+y/3;
}
void init()
{
    memset(vx,0,sizeof(vx));
    memset(vy,0,sizeof(vy));
    memset(vk,0,sizeof(vk));
    ANS=0;
    FOR(i,0,8)
    {
        FOR(j,0,8)
        {
            cin>>a[i][j];
        }
    }
    //memset(v,0,sizeof(v));
}
bool doit()
{
    FOR(i,0,8)
    {
        FOR(j,0,8)
        {
            if (a[i][j]!=0)
            {
                if (!vx[i][a[i][j]])
                    vx[i][a[i][j]]=1;
                else return false;

                int k=getk(i,j);
                //cout<<i<<' '<<j<<' '<<"k: "<<k<<endl;
                if (!vk[k][a[i][j]])
                    vk[k][a[i][j]]=1;
                else return false;
            }

            if (a[j][i]!=0)
            {
                if (!vy[i][a[j][i]])
                    vy[i][a[j][i]]=1;
                else return false;
            }

        }
    }
    return true;
}
bool check()
{
    bool vvx[10][10]={0};
    bool vvy[10][10]={0};
    bool vvk[10][10]={0};
    FOR(i,0,8)
    {
        FOR(j,0,8)
        {
            if (a[i][j]==0)
                return false;
            if (a[i][j]!=0)
            {
                if (!vvx[i][a[i][j]])
                    vvx[i][a[i][j]]=1;
                else return false;

                int k=getk(i,j);
                //cout<<i<<' '<<j<<' '<<"k: "<<k<<endl;
                if (!vvk[k][a[i][j]])
                    vvk[k][a[i][j]]=1;
                else return false;
            }

            if (a[j][i]!=0)
            {
                if (!vvy[i][a[j][i]])
                    vvy[i][a[j][i]]=1;
                else return false;
            }

        }
    }
    return true;
}
void dfs(int x,int y)
{
    if (ANS>1)
        return;
    while(a[x][y]!=0 && x<=8)
    {
        ++y;
        if (y>8)
        {
            ++x;
            y=0;
        }
    }
    //cout<<x<<' '<<y<<endl;*/
    if (x>8)
    {
        if (check())
            ++ANS;
        /*FOR(i,0,8)
        {
            FOR(j,0,8)
            {
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }*/
        return;
    }
    /*if (a[x][y]!=0)
    {
        if (y==8)
            dfs(x+1,0);
        else
            dfs(x,y+1);
    }*/
    FOR(i,1,9)
    {
        int k=getk(x,y);
        if(!vx[x][i] && !vy[y][i] && !vk[k][i])
        {
            a[x][y]=i;
            vx[x][i]=1;vy[y][i]=1;vk[k][i]=1;
            //cout<<"tian "<<x<<' '<<y<<' '<<i<<endl;
            if (y==8)
                dfs(x+1,0);
            else
                dfs(x,y+1);
            a[x][y]=0;
            vx[x][i]=0;vy[y][i]=0;vk[k][i]=0;
        }
    }
}
int main()
{
    RFF("1106.in");
    WFF("1106.out");
    cin>>T;
    FOR(i,1,T)
    {
        init();
        bool FLAG=doit();
        /*if (!FLAG)
        {
            cout<<"NO\n";
            continue;
        }*/
        dfs(0,0);
        if(ANS==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
