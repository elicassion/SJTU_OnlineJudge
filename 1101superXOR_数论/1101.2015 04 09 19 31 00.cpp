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
		long long int op[15]={0};
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
				ans+=()long long int(5))*(num/long long int(10));
				ans%=long long int(10);
				op[w]=ans;
			}
			else
			{
				op[w]=((cnum%long long int(10))*(long long int(mo+1)))%long long int(10);
			}
			cnum/=long long int(10);
		} 
		for (int j=w;j>=1;--j)
		{
			cout<<op[j];
		}
		cout<<endl;
	}
	return 0;
} 
