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
int N,M,ANS=0x7fffffff,ad_c[300],de_c[300];
string s="";
int even_doit(int mid)
{
    int r=max(M-mid,mid);
    int tmp=0;
    FOR(i,1,r)
    {
        if (mid-i<0)//zuo
        {
            tmp+=ad_c[(int)s[mid+i-1]];
        }
        else if (mid+i-1>M-1)//you
        {
            tmp+=ad_c[(int)s[mid-i]];
        }
        else if (s[mid-i]!=s[mid+i-1])
        {
            tmp+=min(de_c[(int)s[mid-i]]+ad_c[(int)s[mid+i-1]],de_c[(int)s[mid+i-1]]+ad_c[(int)s[mid-i]]);
        }
        else continue;
    }
    return tmp;
}
int odd_doit(int mid)
{
    int r=max(M-1-mid,mid-0);
    int tmp=0;
    FOR(i,1,r)
    {
        if (mid-i<0)
        {
            tmp+=ad_c[(int)s[mid+i]];
        }
        else if (mid+i>M-1)
        {
            tmp+=ad_c[(int)s[mid-i]];
        }
        else if (s[mid-i]!=s[mid+i])
        {
            tmp+=min(de_c[(int)s[mid-i]]+ad_c[(int)s[mid+i]],de_c[(int)s[mid+i]]+ad_c[(int)s[mid-i]]);
        }
        else continue;
    }
    return tmp;
}
int main()
{
    //RFF("1066.in");
    cin>>N>>M;
    if (M==0)
    {
        cout<<0<<endl;
        return 0;
    }
    cin>>s;
    FOR(i,1,N)
    {
        char c;
        //int x,y;
        cin>>c;
        cin>>ad_c[(int)c]>>de_c[(int)c];
    }
    FOR(i,0,M-1)//odd中点枚举
    {
        int tmp_ans_odd=odd_doit(i);
        if (tmp_ans_odd<ANS)
            ANS=tmp_ans_odd;
    }
    FOR(i,0,M)//even中点右枚举
    {
        int tmp_ans_even=even_doit(i);
        if (tmp_ans_even<ANS)
            ANS=tmp_ans_even;
    }
    cout<<ANS<<endl;
}
