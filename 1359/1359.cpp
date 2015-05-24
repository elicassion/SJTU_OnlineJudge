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
//http://acm.sjtu.edu.cn/OnlineJudge/problem/1359
using namespace std;
string s;
const int low=27;
const int cap=1;
long long int sum=0;
int main()
{
    //RFF("1359.in");
    //WFF("t.out");
    getline(cin,s);
    int l=s.length();
    FOR(i,0,l-1)
    {
        if (s[i]>='a' && s[i]<='z')
        {
            sum+=(s[i]-'a'+low)*(i+1);
        }
        else if (s[i]>='A' && s[i]<='Z')
        {
            sum+=(s[i]-'A'+cap)*(i+1);
        }

    }
    cout<<sum<<endl;
    return 0;
}
