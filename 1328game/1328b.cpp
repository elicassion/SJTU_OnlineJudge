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
int T;
int N;
int CT=0;
int MAX=-0x7fffffff;
int MIN=0x7fffffff;
bool v[1000010]={0};
int q1[1000010]={0};
int q2[1000010]={0};
void doit()
{
    MSET(v,0);
    v[0]=1;
    CT=0;
    //MAX=-0x7fffffff;
    //MIN=0x7fffffff;
    cin>>N;
    FOR(i,1,N)
    {
        CIa1(q1,i);
        v[q1[i]]=1;
        //if (q[i]>MAX)
        //    MAX=q[i];
        //if (q[i]<MIN)
        //    MIN=q[i];
    }
    int h1=1;
    int t1=N+1;
    int h2=1;
    int t2=1;
    while (h1<=t1 || h2<=t2)
    {
        bool FLAG=1;
        while (h1<=t1 && FLAG)
        {
            FOR(i,h1+1,t1)
            {
                int x=abs(q1[h1]-q1[i]);
                if (!v[x])
                {
                    v[x]=1;
                    q2[t2++]=x;
                    CT++;
                    FLAG=0;
                }
            }
            h1++;
        }
        FLAG=1;
        while (h2<=t2 && FLAG)
        {
            FOR(i,h2+1,t2)
            {
                int x=abs(q1[h2]-q1[i]);
                if (!v[x])
                {
                    v[x]=1;
                    q1[t1++]=x;
                    CT++;
                    FLAG=0;
                }
            }
            h2++;
        }

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
