#include<iostream>
#include<string>
using namespace std;
int main()
{
    int v,n,c[1010],w[1010];
    int f[10010]={0};
    cin>>v>>n;
    for (int i=1;i<=n;++i)
        cin>>c[i]>>w[i];
    for (int i=1;i<=n;++i)
        for (int j=0;j<=v;++j)
            if (j-c[i]>=0 && f[j-c[i]]+w[i]>f[j])
                f[j]=f[j-c[i]]+w[i];
    cout<<f[v]<<endl;
    return 0;
}
