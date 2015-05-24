#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#define FOR(i,bg,ed) for(int i=bg;i<=ed;++i)

#define MSET(a,i) memset(a,i,sizeof(a))
#define CIa1(a,i) cin>>a[i]
#define CIa2(a,i,j) cin>>a[i][j]
#define COa1(a,i) cout<<a[i]
#define COa2(a,i,j) cout<<a[i][j]
#define RFF(s) freopen(s,"r",stdin)
#define WFF(s) freopen(s,"w",stdout)
using namespace std;
string s;
string cans;
int l;
int main()
{
    //RFF("4009.in");
    //WFF("t.out");
    cin>>s;
    l=s.length();
    cin>>cans;
    FOR(i,2,l)
    {
        if (l%i!=0)
            continue;
        string ans="";
        int p=l/i;
        FOR(j,0,i-1)
        {
            FOR(k,0,p-1)
            {
                ans+=s[k*i+j];
            }
        }
        if (ans==cans)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"No Solution"<<endl;
    return 0;
}
