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
const int MAXN=1000;
int N;
int a[MAXN+10];
int pre[MAXN+10],nxt[MAXN+10];
int curmin=0x7fffffff;
int main()
{
    //RFF("4010.in");
    cin>>N;
    FOR(i,0,N-1)
    {
        cin>>a[i];
        if (a[i]<curmin)
            curmin=a[i];
        if (i==0)
        {
            pre[i]=N-1;
            nxt[i]=1;
        }
        else if (i==N-1)
        {
            pre[i]=N-2;
            nxt[i]=0;
        }
        else
        {
            pre[i]=i-1;
            nxt[i]=i+1;
        }
    }
    FOR(i,0,N-1)
        a[i]-=curmin-1;
    int tN=N;
    int pt=0;
    bool FLAG=0;
    while (tN!=1)
    {
        if (!FLAG)
        {
            for (;;pt=nxt[pt])
            {
                --a[pt];
                if (a[pt]==0)
                {
                    FLAG=1;
                    int tpt=pre[pt];
                    nxt[pre[pt]]=nxt[pt];
                    pre[nxt[pt]]=pre[pt];
                    pt=tpt;
                    --tN;
                    break;
                }
            }
        }
        if (tN==1)
            break;
        if (FLAG)
        {
            for (;;pt=pre[pt])
            {
                --a[pt];
                if (a[pt]==0)
                {
                    FLAG=0;
                    int tpt=nxt[pt];
                    nxt[pre[pt]]=nxt[pt];
                    pre[nxt[pt]]=pre[pt];
                    pt=tpt;
                    --tN;
                    break;
                }
            }
        }

    }
    cout<<pt+1<<endl;
    return 0;
}
