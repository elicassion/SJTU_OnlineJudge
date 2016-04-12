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
long long int MAXINT=0x7ffffffffffffff;
bool isout[1000010]={0};
long long int N,T;
long long int CT=0;
struct run_person{
    long long int stp;
    long long int edp;
    long long int k;

    void build(long long int st, long long int v)
    {
        stp=st;
        k=v;
        edp=stp+k*T;
    }
};
run_person p[1000010];
bool cmp(const run_person &a, const run_person &b)
{
   return (a.stp<b.stp);
}
int main()
{
    //RFF("1365.in");
    //WFF("t.out");
    cin>>N>>T;
    int st,v;
    FOR(i,1,N)
    {
        cin>>st>>v;
        p[i].build(st,v);
    }
    sort(p+1,p+N+1,cmp);
    /*FOR(i,1,N)
    {
        cout<<p[i].stp<<' '<<p[i].k<<' '<<p[i].edp<<endl;
    }*/
    FOR(h,1,N)
    {
        if (!isout[h])
        {
            long long int e=p[h].edp;
            isout[h]=1;
            CT++;
            FOR(i,h+1,N)
            {
                if (!isout[i] && p[i].stp>p[h].stp && p[i].edp>e)
                {
                    isout[i]=1;
                    e = p[i].edp;
                    //cout<<i<<endl;
                }
            }
        }

    }
    cout<<CT<<endl;
    return 0;
}
