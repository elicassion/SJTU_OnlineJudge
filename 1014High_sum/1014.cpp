#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int a[100010]={0},b[100010]={0};
void init(int p[])
{
    string s;
    cin>>s;
    int l=s.length();
    p[0]=l;
    for (int i=l-1;i>=0;i--)
        p[l-i]=s[i]-'0';
}
int main()
{
    init(a);
    init(b);
    int j=0;
    for (int i=1;i<=max(a[0],b[0])+2;++i)
    {
        a[i]+=b[i]+j;
        j=a[i]/10;
        a[i]%=10;
    }
    int p=100009;
    while (a[p]==0)
        p--;
    if (p==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for (int i=p;i>=1;i--)
        cout<<a[i];
    return 0;
}
