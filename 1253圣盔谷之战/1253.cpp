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
int M,N,K;
struct node{
    int x;
    int y;
    int num;
};
node mp[700];
bool cmp(node x,node y)
{
    return (x.num>y.num);
}

int main()
{
    //RFF("1253.in");
    cin>>M>>N>>K;
    int ct=M*N;
    for (int i=1;i<=M;++i)
    {
        for (int j=1;j<=N;++j)
        {
            int k=(i-1)*N+j;
            mp[k].x=i;
            mp[k].y=j;
            cin>>mp[k].num;
        }
    }
    sort(mp+1,mp+ct+1,cmp);
    int cur_k=0,ANS=0;
    node cur_n;
    if (mp[1].num==0)
    {
        cout<<0<<endl;
        return 0;
    }
    FOR(i,1,ct)
    {
        //cout<<mp[i].num<<endl;
        if (mp[i].num==0)
        {
            cout<<ANS<<endl;
            return 0;
        }
        if (i==1)
        {
            int tmp=cur_k+mp[i].x*2+1;
            if (tmp<=K)
            {
                ANS+=mp[i].num;
                cur_k += mp[i].x+1;
                cur_n = mp[i];
                //cout<<"tmp: "<<tmp<<" ANS: "<<ANS<<" cur_n: "<<cur_n.x<<' '<<cur_n.y<<" cur_k: "<<cur_k<<endl;
            }
            else
            {
                cout<<0<<endl;
                return 0;
            }
        }
        else
        {
            int tmp=cur_k+abs(cur_n.x-mp[i].x)+abs(cur_n.y-mp[i].y)+mp[i].x+1;
            if (tmp<=K)
            {
                ANS+=mp[i].num;
                cur_k +=abs(cur_n.x-mp[i].x)+abs(cur_n.y-mp[i].y)+1;
                cur_n = mp[i];
                //cout<<"tmp: "<<tmp<<" ANS: "<<ANS<<" cur_n: "<<cur_n.x<<' '<<cur_n.y<<" cur_k: "<<cur_k<<endl;
            }
            else
            {
                cout<<ANS<<endl;
                return 0;
            }
        }
    }
    cout<<ANS<<endl;
    return 0;
}
