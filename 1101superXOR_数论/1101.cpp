#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	//freopen("1101.in","r",stdin);
	//freopen("1101.out","w",stdout);
	long long int num;
	int t;
	cin>>t;
	for (int ti=1;ti<=t;++ti)
	{
		cin>>num;
		int mo=num%10;
		int op[15]={0};
		int w=0;
		long long int cnum=num;
		while (cnum!=0)
		{
			w++;
			long long int ans=0;
			if (w==1)
			{
				for (int i=1;i<=mo;++i)
				{
					ans+=i;
				}
				ans+=5*(num/10);
				ans%=10;
				op[w]=ans;
			}
			else
			{
				op[w]=((cnum%10)*(mo+1))%10;
			}
			cnum/=10;
		} 
		int f=1;
		for (int j=w;j>=1;--j)
		{
			if (op[j]!=0)
			{
				f=j;
				break;
			}
		} 
		for (int j=f;j>=1;--j)
		{
			cout<<op[j];
		}
		cout<<endl;
	}
	return 0;
} 
