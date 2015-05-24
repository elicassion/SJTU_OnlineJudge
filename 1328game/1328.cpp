#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#define FOR(i,bg,ed) for(int i=bg;i<=ed;++i)
#define RFOR(i,bg,ed) for(int i=bg;i>=ed;--i)
#define MSET(a,i) memset(a,i,sizeof(a))
#define CIa1(a,i) cin>>a[i]
#define CIa2(a,i,j) cin>>a[i][j]
#define COa1(a,i) cout<<a[i]
#define COa2(a,i,j) cout<<a[i][j]
#define RFF(s) freopen(s,"r",stdin)
#define WFF(s) freopen(s,"w",stdout)
using namespace std;
bool v[1000010]={0};
int T;
int N;
int q[1000010]={0};
int CT=0;
int MAX=-0x7fffffff;
int MIN=0x7fffffff;
void doit()
{
    MSET(v,0);
    MSET(q,0);
    v[0]=1;
    CT=0;
    MAX=-0x7fffffff;
    MIN=0x7fffffff;
    cin>>N;
    int h=1;
    int t=N+1;
    FOR(i,1,N)
    {
        CIa1(q,i);
        v[q[i]]=1;
        if (q[i]>MAX)
            MAX=q[i];
        if (q[i]<MIN)
            MIN=q[i];
    }
    bool FLAG=1;
    int tmpt2=1;
    while (FLAG)
    {
        int tmpt=t;
        FLAG=0;
        FOR(i,tmpt2,tmpt-1)
        {
            RFOR(j,i,h)
            {
                int x=abs(q[i]-q[j]);
                if (!v[x])
                {
                    v[x]=1;
                    q[t++]=x;
                    CT++;
                    FLAG=1;
                }
            }
        }
        tmpt2=tmpt;
    }
}
void prt()
{
    if (CT%2==1)
        cout<<"Alice"<<endl;
    else
        cout<<"Bob"<<endl;
}
int main()
{
    //RFF("1328.in");
    //WFF("t.out");
    cin>>T;
    FOR(ti,1,T)
    {
        doit();
        prt();
    }
    return 0;
}
