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
int IEQ,IIQ,N;
int EQ[500],IQ[500];
int maxQ=-0x7fffffff;
struct node{
    int act;
    int eq; //tili
    int iq; //zhili
};
node q[2000010]; //整个过程eq>0
int main()
{
    RFF("1124.in");
    cin>>N;
    cin>>IEQ>>IIQ;
    int ct=0;
    while (cin>>EQ[ct+1]>>IQ[ct+1])
    {
        if (EQ[ct+1]<=0 && IQ[ct+1]<=0)
            continue;
        else
            ++ct;
    }//cout<<EQ[i]<<IQ[i]<<endl;
    N=ct;
    int h=1,t=2;
    q[h].act=0;
    q[h].eq=IEQ;
    q[h].iq=IIQ;
    while (h!=t)
    {
        node cur=q[h];
        FOR(i,cur.act+1,N)
        {
            int nx_eq=cur.eq+EQ[i];
            if (nx_eq>=0)
            {
                node next;
                next.act=i;next.eq=nx_eq;next.iq=cur.iq+IQ[i];
                q[t++]=next;
                if (t>=2000010)
                {
                    cout<<"FUCK"<<endl;
                }
            }
        }
        h++;
    }
    FOR(i,1,t-1)
    {
        //cout<<q[i].act<<' '<<q[i].eq<<' '<<q[i].iq<<endl;
        int tmp=q[i].eq*q[i].iq;
        if (q[i].iq>70 && tmp>maxQ)
            maxQ=tmp;
    }
    if (maxQ<=0)
        cout<<"Death"<<endl;
    else
        cout<<maxQ<<endl;
}
