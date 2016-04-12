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
int M;
int a[3]={2,3,5};
long long int f[2000010]={0};
int main()
{
    //RFF("1396.in");
    //WFF("1396.out");
	cin>>M;
    f[0]=1;
    //f[2]=1;
    //f[3]=1;
    //f[4]=1;
    //f[5]=2;
    for (int j=0;j<=2;++j)
    {
        for (int i=1;i<=2000000;++i)
        {
            if (i-a[j]>=0)
            {
                f[i]+=f[i-a[j]];
            }
        }
    }
    /*for (int i=1; i<=200; ++i)
    {
    	cout<<f[i]<<' ';
    }
    cout<<endl;*/
    for (int i=1; i<=M; ++i)
    {
    	int x;
    	cin>>x;
    	/*if (x==0)
    	{
    		cout<<1<<endl;
    	}
    	else*/
    		cout<<f[x]<<endl;
    }
    return 0;
}
