#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100002];
int rp[100002];
int n;
int ct1=0;
void pt(int l,int r)
{
    cout<<"{";
    for (int i=l;i<=r-1;++i)
        cout<<a[i]<<", ";
    cout<<a[r]<<"}";
}
int main()
{
	int x;
	cin>>n;
	int tmp=-0x7ffffff;
	for (int i=1;i<=n;++i)
	{
		cin>>x;
		a[i]=x;
		if (x<=tmp)
        {
            ct1+=1;
            rp[ct1]=i-1;
        }
		tmp=x;
	}
	ct1++;
	rp[ct1]=n;
    rp[0]=0;
	cout<<ct1<<endl;
	cout<<"½âÊÍ: ";
	pt(1,n);
    cout<<" = ";
    for (int i=0;i<ct1-1;++i)
    {
        pt(rp[i]+1,rp[i+1]);
        cout<<" + ";
    }
    pt(rp[ct1-1]+1,rp[ct1]);
	return 0;
}
