#include<iostream>
using namespace std;
int main()
{
	int n;
	bool v[102]={0};
	bool dv[102][102]={0};
	int a[10002];
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		v[a[i]]=1;
	}
	for (int j=1;j<=n;++j)
	{
		for (int i=1;i<=n;++i)
		{
			int x,y;
			if (i!=j)
			{
				x=a[j];
				y=a[i];
			}
			else
				continue;
			int ma=max(x,y);
			int mi=min(x,y);
			if (dv[ma][mi]==0)
			{
				dv[ma][mi]=1;
				int d=ma/mi;
				//cout<<"d: "<<d<<endl;
				if (v[d]==0)
				{
					v[d]=1;
					n++;
					a[n]=d;
				}
			}
			else
				continue;
		}
	}
	cout<<n<<endl;
	return 0; 
} 
