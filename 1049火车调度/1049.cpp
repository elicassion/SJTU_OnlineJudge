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
using namespace std;
int T;
int N,M;
int a[1010];
bool doit()
{
    cin>>N>>M;
    FOR(i,0,N-1)
        SCIa1(a,i);
    stack<int> S;
    int h=0;
    FOR(i,0,N-1)
    {
        if(i!=a[h])
        {
            S.push(i);
            if (S.size()>M)
                return false;
        }
        else
            h++;
        //cout<<S.top()<<endl;
        while(S.size()!=0 && h<N && S.top()==a[h])
        {
            S.pop();
            h++;
        }
    }
    if (S.size()==0)
        return true;
    else
        return false;
}
int main()
{
    //RFF("1049.in");
    //WFF("t.out");
    cin>>T;
    FOR(i,1,T)
    {
        if(doit())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
