#include<iostream>
#include<cstdio>
using namespace std;
long long int f[70]={0};
int main()
{
    f[0]=1;
    f[1]=1;
    int n;
    cin>>n;
    for (int i=2;i<=n;++i)
        f[i]=f[i-1]+f[i-2];
    cout<<f[n]<<endl;
    return 0;
}
