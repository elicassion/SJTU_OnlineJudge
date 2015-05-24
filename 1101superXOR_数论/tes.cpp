#include<iostream>
#include<cstring>
using namespace std;
int ans[15]={0};
int p[15]={0};
void i2p(long long int a)
{
	int k=0;
	while (a!=0)
	{
		p[k]=a%10;
		a/=10;
		k++;
	}
}
void plu()
{
	for (int i=0;i<=11;++i)
	{
		ans[i]=(ans[i]+p[i])%10;
	}
}
int main()
{
	long long int n;
	cin>>n;
	for (long long int i=1;i<=n;++i)
	{
		i2p(i);
		plu();
	}
	int f;
	for (int i=11;i>=0;--i)
	{
		if (ans[i]!=0)
		{
			f=i;
			break;
		}
	}
	for (int i=f;i>=0;--i)
	{
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
