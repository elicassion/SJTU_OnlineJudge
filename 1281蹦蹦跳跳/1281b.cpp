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
int M,N,M1,M2;
int bgx,bgy,edx,edy;
int dx[8];
int dy[8];
int a[60][60];
bool v[60][60]={0};
struct node{
    int x;
    int y;
    int t;
};
node q[5000000];

void init_d()
{
    dx[0]=-M1;
    dx[1]=-M2;
    dx[2]=-M2;
    dx[3]=-M1;
    dx[4]=M1;
    dx[5]=M2;
    dx[6]=M2;
    dx[7]=M1;
    dy[0]=-M2;
    dy[1]=-M1;
    dy[2]=M1;
    dy[3]=M2;
    dy[4]=M2;
    dy[5]=M1;
    dy[6]=-M1;
    dy[7]=-M2;
    /*FOR(i,0,7)
    {
        cout<<dx[i]<<' ';
    }
    cout<<endl;*/
}
void init_map()
{
    FOR(i,1,M)
    {
        FOR(j,1,N)
        {
            cin>>a[i][j];
            if (a[i][j]==3)
            {
                bgx=i;bgy=j;
            }
            if (a[i][j]==4)
            {
                edx=i;edy=j;
            }
        }
    }
}
void bfs()
{

    node bg;
    bg.x=bgx;bg.y=bgy;bg.t=0;
    q[1]=bg;
    //cout<<bgx<<' '<<bgy<<endl;
    //cout<<edx<<' '<<edy<<endl;
    int head=1,tail=2;
    v[bgx][bgy]=1;
    while(head!=tail)
    {
        int cx=q[head].x;
        int cy=q[head].y;
        int ct=q[head].t;
        //cout<<cx<<' '<<cy<<' '<<ct<<endl;
        //system("pause");
        /*if (cx==edx && cy==edy)
        {
            cout<<ct<<endl;
            return;
        }*/
        FOR(i,0,7)
        {
            //cout<<i<<' ';
            int tx=cx+dx[i];
            int ty=cy+dy[i];
            //cout<<tx<<' '<<ty<<endl;
            /*if (a[tx][ty]==4)
                cout<<"FUCK"<<' '<<i<<endl;*/
            if (tx<1 || tx>M || ty<1 || ty>N)
                continue;
            if (a[tx][ty]==1 && !v[tx][ty])
            {
                node nxt;
                nxt.x=tx;
                nxt.y=ty;
                nxt.t=ct+1;
                q[tail++]=nxt;
                if (tail>=5000000)
                    tail=1;
            }
            else if (a[tx][ty]==4)
            {
                //cout<<ct<<"FUCK"<<endl;
                cout<<ct+1<<endl;
                return;
            }
        }
        head++;
        if (head>=5000000)
            head=1;
    }

}
int main()
{
    //RFF("1281.in");
    cin>>M>>N>>M1>>M2;
    init_d();
    init_map();
    bfs();
}
