#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<stdio.h>
using namespace std;
int aa[202]={0},bb[202]={0},c[210]={0},ans[101][110];
int zero=0;
int *a,*b;
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
		if (b[i]==0)
        {
            ans[i][0]=-1;
            zero++;
            continue;
        }
		int g=0;
		for(int j=1;j<=a[0];++j)
		{
            ans[i][++ans[i][0]]=a[j]*b[i]+g;
			g=ans[i][ans[i][0]]/10;
			ans[i][ans[i][0]]%=10;
		}
		while(g>0)
		{
                ans[i][++ans[i][0]]+=g%10;
				g/=10;
		}
	}

	for (int i=1;i<=b[0];++i)
    {
        for (int j=ans[i][0];j>=1;--j)
        {
            c[i-1+j]+=ans[i][j];
        }
    }
    int q=209;
    while (c[q]==0)
        q--;
    if (q>0)
        c[0]=q;
    else
    {
        c[0]=1;
        return;
    }
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

}
void print()
{
     int pc=max(max(c[0],a[0]),b[0]);
     for (int i=pc;i>=1;i--)
     {
        if (i>a[0])
            cout<<' ';
        else
            cout<<a[i];
     }
     cout<<endl;

     for (int i=pc;i>=1;i--)
     {
        if (i>b[0])
            cout<<' ';
        else
            cout<<b[i];
     }
     cout<<endl;

     for (int i=1;i<=pc;++i)
        cout<<'-';
     cout<<endl;

    if (a[0]==1 && a[1]==0)
    {
        for (int i=1;i<=pc-1;++i)
            cout<<' ';
        cout<<0<<endl;
        return;
    }
    if (zero==b[0])
    {
        for (int i=1;i<=pc-1;++i)
            cout<<' ';
        cout<<0<<endl;
        return;
    }

    if (b[0]-zero==1)
    {
        for (int i=pc;i>c[0];--i)
            cout<<' ';
        for (int i=c[0];i>=1;--i)
            cout<<c[i];
        cout<<endl;
        return;
    }

     for (int i=1;i<=b[0];++i)
     {
        if (ans[i][0]==-1)
            continue;
        for (int k=1;k<=pc-ans[i][0]-i+1;++k)
            cout<<' ';
        for (int k=ans[i][0];k>=1;k--)
            cout<<ans[i][k];
        for (int k=1;k<=i-1;++k)
            cout<<' ';
        cout<<endl;
     }

     for (int i=1;i<=pc;++i)
        cout<<'-';
     cout<<endl;

     for (int i=c[0];i>=1;--i)
        cout<<c[i];
     cout<<endl;
}
int main()
{
	freopen("1274.in","r",stdin);
    freopen("1274.out","w",stdout);
	memset(ans,0,sizeof(ans));
	init(aa);
	init(bb);
	if (bb[0]==1 && aa[0]>2)
    {
        a=bb;
        b=aa;
    }
    else
    {
        a=aa;
        b=bb;
    }
    intx();
    print();
}
