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
using namespace std;
int N;
int a[1010];
int f[1010][1010]={0};
int ANS = -0x7fffffff;
int main()
{
    //RFF("4020.in");
    //WFF("4020.out");
    cin>>N;
    for (int i=1;i<=N;++i)
    {
    	cin>>a[i];
    }
    for (int i=1;i<=N;++i)
    {
        for (int j=0;j<=i;++j)
        {
            if (a[i]==i-j)
            	f[i][j]=f[i-1][j]+1; //stay
            f[i][j]=max(max(f[i-1][j],f[i-1][j-1]),f[i][j]);
        }
    }
    for (int i=0;i<=N;++i)
    {
    	ANS = max(ANS,f[N][i]);
    }
    cout<<ANS<<endl;
    return 0;
}
