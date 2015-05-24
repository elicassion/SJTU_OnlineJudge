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
int S,T;
int f[200010]={0}; //以i为结尾最多多长
int maxl=1;
long long int clt[200010]={0}; //长度为i有多少个
long long int ct[200010]={0};
int main()
{
    //RFF("1012.in");
    //WFF("t.out");
    cin>>S>>T;
    FOR(i,S,T)
    {
        f[i]=1;
        ct[i]=1;
    }
    clt[1]=T-S+1;
    FOR(i,S,T)
    {
        FOR(j,1,200)
        {
            if (i*j%100==0)
            {
                int next=i+i*j/100;
                if (next>T)
                    break;
                if (f[i]+1>f[next])
                {
                    f[next]=f[i]+1;
                    ct[next]=ct[i];
                }
                else if (f[i]+1==f[next])
                {
                    ct[next]+=ct[i];
                }
                maxl=max(maxl,f[next]);
                clt[f[i]+1]+=ct[i];
            }
        }
    }
    cout<<maxl<<endl;
    cout<<clt[maxl]<<endl;
    return 0;
}
