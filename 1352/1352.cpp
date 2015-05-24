#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("1352.in","r",stdin);
    long long int m,n;
    cin>>m>>n;
    int x;
    long long int sum=0;
    sum+=m;
    long long int k=m;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        if (k<x)
            break;
        sum+=k/x;
        k=k%x+k/x;

    }

    while (k>=x)
    {
        sum+=k/x;
        k=k%x+k/x;
    }
    cout<<sum<<' '<<k<<endl;
    return 0;
}
