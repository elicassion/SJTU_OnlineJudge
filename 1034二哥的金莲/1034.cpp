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
int N,K;
int v[400010]={0};
int main()
{
    //RFF("1034.in");
    //WFF("t.out");
    scanf("%d %d",&N,&K);
    FOR(i,0,N-1)
    {
        scanf("%d",&v[i]);
        v[i+N]=v[i];
    }
    int maxdv=0;
    int minmaxdv=0;
    int maxdvloc;
    FOR(i,0,K-1)
    {
        if (v[i]>maxdv)
        {
            maxdv=v[i];
            maxdvloc=i;
        }
    }
    minmaxdv=maxdv;
    FOR(i,1,N-1)
    {
        if(v[i+K-1]<maxdv && maxdvloc>=i)
            continue;
        else if (v[i+K-1]>=maxdv && maxdvloc>=i)
        {
            maxdv=v[i+K-1];
            maxdvloc=i+K-1;
        }
        else if (maxdvloc<i)
        {
            maxdv=0;
            FOR(j,i,i+K-1)
            {
                if (v[j]>maxdv)
                {
                    maxdv=v[j];
                    maxdvloc=j;
                }
            }
        }
        if (maxdv<minmaxdv)
            minmaxdv=maxdv;
    }
    /*FOR(i,0,N-1)
    {
        cout<<pv[i]<<endl;
    }*/
    cout<<minmaxdv<<endl;
    return 0;
}
