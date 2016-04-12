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
int a[510];
int f[2010]={0};
//int g[2010]={0};
int main()
{
    //RFF("1.in");
    //WFF("1.out");
    f[0]=1;
    cin>>N;
    for (int i=1;i<=N;++i)
    	cin>>a[i];
    for (int i=1;i<=N;++i)
    {
    	for (int j=2000;j>=1;--j)
    	{
    		if (j-a[i]>=0)
    		{
    			f[j]+=f[j-a[i]];
    		}
    	}
    }
    //bool FLAG=false;
    /*for (int i=1;i<=2000;++i)
    	cout<<f[i]<<' ';*/
    for (int i=2000;i>=2;--i)
    {
    	if (f[i]!=0 && i%2 ==0 && f[i/2]>1 )
    	{
    		cout<<i/2<<endl;
    		return 0;
    	}
    }
    cout<<"Impossible"<<endl;
    return 0;
}
