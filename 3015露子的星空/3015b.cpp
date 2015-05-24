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
int N,M;
int f[100010];
int CT=0;
bool v[100010]={0};
int ISO;
int fd(int x)
{
    int fat=x;
    while(fat!=f[fat])
        fat=f[fat];
    while(x!=fat)
    {
        int pre=f[x];
        f[x]=fat;
        x=pre;
    }
    return fat;
}
void join(int x, int y)
{
    int rootx = fd(x) , rooty = fd(y);
    if(rootx != rooty)
    {
        f[rootx] = rooty;
        CT--;
    }
    return;
}
int main()
{
    //RFF("3015.in");
    //WFF("t.out");
    //ios::sync_with_stdio(false);
    scanf("%d %d",&N,&M);
    FOR(i,1,N)
        f[i]=i;
    CT=N;
    ISO=N;
    //getchar();
    FOR(i,1,M)
    {
        char com[2];
        int x,y;
        scanf("%s",com);
        if (com[0]=='a')
        {
            scanf("%d %d",&x,&y);
            join(x,y);
            if (!v[x])
            {
                v[x]=1;
                ISO--;
            }
            if (!v[y])
            {
                v[y]=1;
                ISO--;
            }
        }
        else if (com[0]=='b')
        {
            printf("%d\n",CT-ISO);
        }
        else if (com[0]=='c')
        {
            scanf("%d %d",&x,&y);
            if (fd(x)==fd(y))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
