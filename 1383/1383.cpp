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
long long int f[12][1<<11]; //状态1为横铺或纵铺第二格，状态0为纵铺第一格
int W,H;
bool ok(int a)
{
    int x=1;
    int count=0;
    for (int i=0;i<H;i++,x<<=1)
    {
        if (a&x)//此位为1
            count++;
        else //此位为0
        {
            if (count&1)//单个1与单个0间隔 不可
                return false;
            count=0;//1累计数清零
        }
    }
    return !(count&1);//如果1是奇数 该层不能密铺
}

void init()
{
    /*for (int i=1;i<=11;++i)
    {
        for (int j=0;j<(1<<H);++j)
            f[i][j]=0;
    }*/
    for (int i=0;i<(1<<H);++i)
        if (ok(i))
            f[1][i]=1;
    /*for (int i=0;i<(1<<H);++i)
        cout<<f[1][i]<<' ';
    ENTER;*/
    //f[0][(1<<H)-1]=1;
}


bool match(int j,int k)
{
    for (int i=1;i<(1<<H);)//检查j,k每一位
    {
        if ((j&i)==0 && (k&i)==0) //上下都为0
            return false;
        if ((j&i) && (k&i)) //上下都为1 不可竖铺 只能横铺
        {
            if ((j&(i<<1)) && (k&(i<<1)))//检查横铺 如果下层前一格是1  上层前一格是1 此格已横铺
            {
                i<<=2;
                continue;
            }
            else return false;//其他情况不可横铺 同时因前提不可竖铺 故false
        }
        i<<=1;
    }
    return true;//过了所有检查 状态可转移
}
void doit()
{
    init();
    for (int i=2;i<=W;++i)
    {
        for (int j=0;j<(1<<H);++j)//当前
        {
            for (int k=0;k<(1<<H);++k)//上一列
            {
                if (match(j,k))
                    f[i][j]+=f[i-1][k];
            }
            //cout<<f[i][j]<<' ';
        }
        //ENTER;
    }
}
int main()
{
    while(cin>>W>>H)
    {
        if (W==0 && H==0)
            return 0;
        if ((W*H)%2==1)
        {
            cout<<0<<endl;
            continue;
        }
        if (W<H)
        {
            int t=W;
            W=H;
            H=t;
        }
        memset(f,0,sizeof(f));
        doit();
        cout<<f[W][(1<<H)-1]<<endl;
    }
    return 0;
}
