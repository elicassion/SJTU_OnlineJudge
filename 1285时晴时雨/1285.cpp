#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_1(i, a, b) for (int i=int(a);i<=int(b);++i)
#define DWN_1(i, b, a) for (int i=int(b);i>=int(a);--i)
#define REP_C(i, n) for (int n____=int(n),i=0;i<n____;++i)
#define FOR_C(i, a, b) for (int b____=int(b),i=a;i<b____;++i)
#define DWN_C(i, b, a) for (int a____=int(a),i=b-1;i>=a____;--i)
#define REP_N(i, n) for (i=0;i<int(n);++i)
#define FOR_N(i, a, b) for (i=int(a);i<int(b);++i)
#define DWN_N(i, b, a) for (i=int(b-1);i>=int(a);--i)
#define MOD 1000000007
#define LL long long int
using namespace std;
inline char* RS(char *s){scanf("%s", s); return s;}
inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
inline void MUL(int &a, int b){a = (LL)a * b % MOD;}
inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}
inline int pow(int a, int b){
    int c=1;
    while (b){
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}
inline int pdt(int a, int b){return (LL)a * b % MOD;}
inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
const int N = 1000009;

int F0[N]={0}, F1[N]={0}, G0[N]={0}, G1[N]={0};
char s[N];
int L[N]={0}, R[N]={0}, n, k, k_, l, r;

int main()
{

    //freopen("1285.in", "r", stdin);
    scanf("%d %d",&n,&k);
    RS(s+1);
    k_ = k + 1;

    REP_1(i, n)
        L[i] = L[i-1] + (s[i]=='X');//左侧有多少个X
    DWN_1(i, n, 1)
        R[i] = R[i+1] + (s[i]=='X');//右侧有多少个X

    l = 0, r = 0;

    REP_1(i, n)
    {
        if (s[i] == 'X' || s[i] == 'B')
            ++r;
        else
            l = r = i;
        F1[i] = sum(pdt(s[i] == 'X' ? 2 : 1, F1[i-1]),  F0[i] = r-l>=k && s[i-k] != 'B' ? dff(pow(2, L[i-k_]), F1[i-k_]) : 0);
    }

    l = n+1, r = n+1;
    DWN_1(i, n, 1)
    {
        if (s[i] == 'X' || s[i] == 'W')
            --l;
        else
            r = l = i;
        G1[i] = sum(pdt(s[i] == 'X' ? 2 : 1, G1[i+1]), G0[i] = r-l>=k && s[i+k] != 'W' ? dff(pow(2, R[i+k_]), G1[i+k_]) : 0);
    }
    int res = 0; FOR(i, 1, n) INC(res, pdt(F0[i], G1[i+1]));
    cout<<res<<endl;
}
