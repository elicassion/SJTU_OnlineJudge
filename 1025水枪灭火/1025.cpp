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
const int MOD=0x7fffffff;
inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
inline void MUL(int &a, int b){a = (LL)a * b % MOD;}
inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}
inline int pow(int a, int b){int c=1;while (b){if (b&1) MUL(c, a);MUL(a, a), b >>= 1;}return c;}
inline int pdt(int a, int b){return (LL)a * b % MOD;}
inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
int N;
int CT=0;
int MAX[20010]={0};
int MIN[20010]={0};
int AMAX=-0X7fffffff;
int AMIN=0x7fffffff;
int main()
{
    RFF("1025.in");
    //WFF("t.out");
    cin>>N;
    FOR(i,1,N)
    {
        MAX[i]=-0x7fffffff;
        MIN[i]=0x7fffffff;
    }
    FOR(i,1,N)
    {
        int l,r;
        int tmct=CT;
        cin>>l>>r;
        if (r>AMAX)
            AMAX=r;
        if (l<AMIN)
            AMIN=l;
        FOR(j,0,tmct)
        {
            if (l>MAX[j])
            {
                CT++;
                MIN[CT]=l;
                MAX[CT]=r;
                break;
            }
            else if (r<MIN[j])
            {
                CT++;
                MIN[CT]=l;
                MAX[CT]=r;
                break;
            }
            if (l<=MIN[j] && l<=MAX[j])
                MIN[j]=l;
            if (r>=MAX[j] && l<=MAX[j])
                MAX[j]=r;
        }
    }
    int ans=0;
    FOR(i,0,CT)
    {
        ans-=
    }
    return 0;
}
