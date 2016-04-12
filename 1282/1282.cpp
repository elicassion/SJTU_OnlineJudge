#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>
#define RFF(s) freopen(s,"r",stdin)
#define WFF(s) freopen(s,"w",stdout)
#define ABS(x) (x>0?x:-x)
using namespace std;
int N;
int a[2010];
int b[2010];
int ori[2010];
int f[2010][2010];
int g[2010][2010];
int ANS=0x7fffffff;
int main()
{
    //RFF("1282.in");
    //WFF("1282.out");
    cin>>N;
    for (int i=1; i<=N; ++i)
    {
    	cin>>ori[i];
    	b[i]=a[i]=ori[i];
    }
    sort(a+1,a+N+1);
    sort( b+1, b+N+1 , greater<int>() );
    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=N; ++j)
        {
            f[i][j] = g[i-1][j] + abs(ori[i]-a[j]);// fij是前i个合法 且第i个值为排序后数列第j个值
            if(j == 1) g[i][j] = f[i][j];//gij是相同的i中 j个 fij的最小值 即gij=min{f[i][1->j]} 即1->i 1->j局部最优解
            else g[i][j] = min(f[i][j],g[i][j-1]);//用g的原因是以空间换时间，节省了每次从i-1找min fi-1j的时间
        }
    }
    for(int i=1; i<=N; ++i)
        ANS=min(ANS,f[N][i]);
    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=N; ++j)
        {
            f[i][j] = g[i-1][j] + abs(ori[i]-b[j]);
            if(j == 1) g[i][j] = f[i][j];
            else g[i][j] = min(f[i][j],g[i][j-1]);
        }
    }
    for(int i=1; i<=N; ++i)
        ANS=min(ANS,f[N][i]);
    cout<<ANS<<endl;
	//system("pause");
    return 0;
}
