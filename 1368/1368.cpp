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
struct node{
    node *next;
    node *pre;
    int data;
};
int N,M;
node *head=new node;
long long int ans=0;
int main()
{
    //RFF("1368.in");
    scanf("%d %d",&N,&M);
    node *cur=head;
    node *prr=NULL;
    FOR(i,1,N)
    {
        cur->data=i;
        cur->pre=prr;
        cur->next=new node;
        prr=cur;
        cur=cur->next;
    }
    head->pre=cur;
    cur->next=head;
    node *now=head;
    FOR(i,1,M)
    {
        int x,k,w;
        scanf("%d",&x);
        if (x==0)
        {
            scanf("%d",&k);
            FOR(i,1,k-1)
            {
                now=now->next;
            }
            node *tmp=now;
            node *tmpnext=now->next;
            node *tmppre=now->pre;
            tmppre->next=tmpnext;
            now->next->pre=tmppre;
            delete tmp;
            now=tmpnext;
        }
        else
        {
            scanf("%d %d",&k,&w);
            FOR(i,1,k-1)
            {
                now=now->next;
            }
            node *tmp=new node;
            node *tmp1=now;
            node *tmp2=now->next;
            now->next->pre=tmp;
            now->next=tmp;
            tmp->pre=tmp1;
            tmp->next=tmp2;
            tmp->data=w;
            now=tmp;
        }
    }
    node *go=head;
    while(go->next!=head)
    {
        ans+=go->data;
    }
    cout<<ans<<endl;
}
