#include<iostream>
#include<string.h>
using namespace std;
int f[31][31]={0};
int m,n;
void dp()
{
	f[1][2]=1;
	f[1][n]=1;
	for(int i=2;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			int l,r;
		    if((j-1)==0)
				l=n;
			else l=j-1;
			if((j+1)>n)
				r=1;
			else r=j+1;
			f[i][j]=f[i-1][l]+f[i-1][r];
		}
	}
}
void print()
{
	cout<<f[m][1]<<endl;
}
int main()
{
	cin>>n>>m;
	dp();
	print();
	return 0;
}

