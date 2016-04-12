#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
string a,b;
int f[1010][1010]={0};
int main()
{
    cin>>a>>b;
    int al=a.length();
    int bl=b.length();
    for (int i=1;i<=al;++i)
    {
        for (int j=1;j<=bl;++j)
        {
            if (a[i-1]==b[j-1])
            {
                f[i][j]=f[i-1][j-1]+1;
            }
            else
            {
                f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
    }
    cout<<f[al][bl]<<endl;
    return 0;
}
