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
int f[2010][2010];
int N,M,ANS=0x7fffffff,min_c[300];
string s;
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
        cin>>c;
        int x,y;
        cin>>x>>y;
        min_c[(int)c]=min(x,y);//取花费最少的增加/删除
        //cout<<min_c[(int)c]<<endl;
    }
    FOR(i,0,M)
        FOR(j,0,M)
        {
            f[i][j]=0x7fffffff;
        }
    FOR(i,0,M-1)
        f[i][i]=0;
    RFOR(i,M-1,0)
    {
        FOR(j,i+1,M-1)
        {
            f[i][j]=min(f[i][j-1]+min_c[(int)s[j]],f[i+1][j]+min_c[(int)s[i]]);
            if (s[i]==s[j])
            {
                if (j>i+1)//不是相同字符
                {
                    f[i][j]=min(f[i][j],f[i+1][j-1]);
                }
                else f[i][j]=0;
            }
            //cout<<"f["<<i<<"]["<<j<<"] "<<f[i][j]<<endl;
        }
    }
    cout<<f[0][M-1]<<endl;
}
