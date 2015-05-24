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
#define SPACE printf(" ")
#define ENTER printf("\n")
#define LL long long int
using namespace std;
const int MAXN=30010;
int N;
int **m;//图
int in[MAXN]={0};//入度
bool v[MAXN]={0};//是否删除过
int ans[MAXN]={0};
priority_queue< int,vector<int>,greater<int> > q;//优先队列 指定greater为比较大小方式 即>
void init()
{
    scanf("%d",&N);
    m=new int*[N+10];
    FOR(i,1,N)
    {
        int k=0;
        scanf("%d",&k);
        m[i]=new int[k+10];
        m[i][0]=k;
        FOR(j,1,k)
        {
            scanf("%d",&m[i][j]);
            in[m[i][j]]++;
        }
    }
}
bool TSort()
{
    FOR(i,1,N)
        if (in[i]==0)
            q.push(i);
    if (q.size()==0)
        return false;
    FOR(i,1,N)
    {
        int now=q.top();
        q.pop();
        if (v[now])
            return false;
        v[now]=1;
        ans[i]=now;
        FOR(j,1,m[now][0])
        {
            int next=m[now][j];
            if (v[next])
                return false;
            in[next]--;
            if (in[next]==0)
                q.push(next);
        }
    }
    return true;
}
void dest()
{
    FOR(i,0,N+9)
    {
        delete[] m[i];
    }
    delete m;
}
int main()
{
    //RFF("3010.in");
    //WFF("t.out");
    init();
    if (TSort())
    {
        printf("%d\n",N);
        FOR(i,1,N)
            SCOa1(ans,i);
        ENTER;
    }
    else
    {
        printf("no solution\n");
    }
    dest();
    return 0;
}
