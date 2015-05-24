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
struct TNode
{
    TNode* left;
    TNode* right;
    char v;
};
TNode* Tree(char* pre, char* in, int L)
{
    if (L==0)
        return NULL;
    TNode* node=new TNode;
    node->v=*pre;
    int rloc=0;
    FOR(i,0,L-1)
    {
        if (in[i]==node->v)
        {
            rloc=i;
            break;
        }
    }
    node->left=Tree(pre+1 ,in ,rloc);
    node->right=Tree(pre+rloc+1 ,in+rloc+1 ,L-rloc-1);
    cout<<node->v;
    return node;
}
int main()
{
    char pre[100];//root left right
    char in[100];// left root right
    int L;
    //RFF("3007.in");
    //WFF("t.out");
    cin>>pre>>in;
    L=strlen(pre);
    Tree(pre,in,L);
    return 0;
}
