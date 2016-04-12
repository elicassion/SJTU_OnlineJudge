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
long long int ans=0;
int N,M;
struct Node
{
    int data;
    struct Node *next;
};

Node *Create()
{
    Node *head;

    head=new Node;
    Node *cur=head;
    head->data=1;
    FOR(i,2,N+1)
    {
        if(i<=N)
        {
            cur->next=new Node;
            cur->next->data=i;
        }

        else
            cur->next=head;


            cur=cur->next;
        else
            cur=
        cout<<i<<endl;
    }
    cur->next=head;
    return head;
}


Node *insert(Node *head,int p,int x)
{
    Node*tmp=head;
    int ct=1;
    for(Node *tmp=head;ct<p;tmp=tmp->next)
    {
            tmp=tmp->next;
            ++ct;
    }
    Node *tmp2=new Node;
    tmp2->data=x;
    tmp2->next=tmp->next;
    tmp->next=tmp2;
    return tmp2;
}


Node* del(Node *head,int p)
{
    Node *tmp=head;
    int ct=1;
    for(Node *tmp=head;ct<p;tmp=tmp->next)
    {
            tmp=tmp->next;
            ++ct;
    }
    tmp->next=tmp->next->next;
    return tmp->next;
}

void sum(Node *head)
{
    for(Node *tmp=head;tmp->next!=head;tmp=tmp->next)
        ans+=tmp->data;
    cout<<ans<<endl;
}

int main()
{
    RFF("1368.in");
    Node *head;
    head=new Node;
    head->data=1;
    head->next=NULL;
    scanf("%d %d",&N,&M);
    Node *cur=head;
    head=Create();
    FOR(i,1,M)
    {
        int x,k,w;
        scanf("%d",&x);
        if (x==0)
        {
            scanf("%d",&k);
            cur=del(cur,k);
        }
        else
        {
            scanf("%d %d",&k,&w);
            cur=insert(cur,k,w);
        }
    }
    sum(cur);
    return 0;
}
