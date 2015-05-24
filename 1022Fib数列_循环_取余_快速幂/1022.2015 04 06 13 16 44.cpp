#include<iostream>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	int f1=1;
	int f2=1;
	int f3;
	int xh=2;
	while (1)
	{
		f3=(f2+f1)%2010;
		f1=f2;
		f2=f3;
		xh++;
		if (f1==1 && f2==1)
		{
			xh-=2;
			break;
		}
	}
	//cout<<xh<<endl;
	
	f1=1;f2=1;
	int k=(n-1)%xh+1;
	if (k==1 || k==2)
	{
		cout<<1<<endl;
		return 0;
	}
	for (int i=3;i<=k;++i)
	{
		f3=(f2+f1)%2010;
		f1=f2;
		f2=f3;
	}
	cout<<f3<<endl;
	return 0;
}
