#include<iostream>
using namespace std;
int f[3400]={0};
int main()
{
    int N;
    cin>>N;
    f[0]=1;
    f[1]=1;
    f[2]=2;
    f[3]=4;
    for (int i=4;i<=N;++i)
    {
        f[i]+=f[i-1];
        for (int j=0;j<i;++j)
        {
            f[i]+=(f[i-2-j]*f[j])%19301;
        }
        f[i]%=19301;
    }
    cout<<f[N]<<endl;
    return 0;
}
