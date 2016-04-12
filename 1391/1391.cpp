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
int H,W;
bool a[20][20]={0};
bool mir[20][20]={0};
int ANS=0x7fffffff;
void cp_map()
{
    for (int i=1;i<=H;++i)
    {
        for (int j=1;j<=W;++j)
        {
            mir[i][j]=a[i][j];
        }
    }
}
void init()
{
    cin>>H>>W;
    int x;
    for (int i=1;i<=H;++i)
    {
        for (int j=1;j<=W;++j)
        {
            cin>>x;
            a[i][j]=x&1;
        }
    }
}
int ct_center(int k)
{
    int ct=0;
    while(k>0)
    {
        ct+=k&1;
        k>>=1;
    }
    return ct;
}
void place(int row,int k)
{
    for (int i=1;i<=W;++i)
    {
        if (k&(1<<(i-1)))
        {
            mir[row-1][i]=!mir[row-1][i];
            mir[row][i-1]=!mir[row][i-1];
            mir[row][i+1]=!mir[row][i+1];
            mir[row+1][i]=!mir[row+1][i];
            mir[row][i]=!mir[row][i];
        }
    }
}
void doit()
{
    bool getdaze=0;
    for (int i=0;i<(1<<W);++i)
    {
        cp_map();
        int ct=ct_center(i);
        place(1,i);
        for (int j=2;j<=H;++j)
        {
            int k=0;
            for (int p=1;p<=W;++p)
            {
                if (mir[j-1][p])
                {
                    k+=(1<<(p-1));
                    //++ct;
                }
            }
            ct+=ct_center(k);
            place(j,k);
            //cout<<ct<<endl;
        }
        /*for (int p=1;p<=H;++p)
        {
            for (int q=1;q<=W;++q)
            {
                cout<<mir[p][q]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;*/
        bool lastok=1;
        for (int j=1;j<=W;++j)
        {
            if (mir[H][j])
            {
                lastok=false;
                break;
            }
        }
        if (lastok)
        {
            getdaze=1;
            ANS=min(ANS,ct);
        }
    }
    if (!getdaze)
        ANS=-1;
}
int main()
{

    init();
    doit();
    cout<<ANS<<endl;
}
