#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<stdio.h>
using namespace std;
int a[1000]={0},b[1000]={0},c[1000]={0};
void init(int p[])
{
    string s;
    cin>>s;
    int l=s.length();
    p[0]=l;
    for (int i=l-1;i>=0;i--)
        p[l-i]=s[i]-'0';
}
void intx()
{
	for(int i=1;i<=b[0];++i)
	{
		int g=0;
		int tp[1000]={0};
		tp[0]=a[0];
		for(int j=1;j<=a[0];++j)
		{
            tp[j]+=a[j]*b[i]+g;
			g=tp[j]/10;
			tp[j]%=10;
		}
		int k=0;
		while(g>0)
		{
                k++;
                tp[++tp[0]]+=g%10;
				g/=10;
		}
		for (int j=i;j<tp[0]+i;++j)
            c[j]+=tp[j-i+1];
	}
    int q=999;
    while (c[q]==0)
        q--;
    if (q>0)
        c[0]=q;
    else
        c[0]=1;
    int jin=0;
    for (int i=1;i<=c[0];++i)
    {
        c[i]+=jin;
        jin=c[i]/10;
        c[i]=c[i]%10;
    }
    while (jin>0)
    {
        c[++c[0]]+=jin%10;
        jin/=10;
    }
     for (int i=c[0];i>=1;--i)
            cout<<c[i];
    cout<<endl;

}
int main()
{
    init(a);
    init(b);
    intx();
    return 0;
}
