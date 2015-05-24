#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[100002];
	int n;
	int x;
	int ct1=0;
	cin>>n;
	int tmp=-0x7ffffff;
	for (int i=1;i<=n;++i)
	{
		cin>>x;
		a[i]=x;
		if (x<=tmp)
			ct1+=1;
		tmp=x;
	}
	ct1++;
	
	int ct2=0;
	tmp=0x7ffffff;
	for (int i=n;i>=1;--i)
	{
		if(a[i]>=tmp)
			ct2++;
		tmp=a[i];
	}
	ct2++;
	
	cout<<min(ct1,ct2)<<endl;
	
	return 0;
} 
