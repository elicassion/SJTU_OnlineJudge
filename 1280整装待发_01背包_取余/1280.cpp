#include<iostream>
#include<stdio.h>
using namespace std;

int n,f;
int ri[2001];
long long int fpack[2001][1001]={0};

int main()
{
	//freopen("1280.in","r",stdin);
	//freopen("1280.out","w",stdout);
	
	cin>>n>>f;
	fpack[0][0]=1;
	for (int i=1;i<=n;++i)
	{
		cin>>ri[i];
		ri[i]%=f;
	}


	for (int i=1;i<=n;++i)
	{
		for (int j=f-1;j>=0;--j)
		{
			if (j>=ri[i])
				fpack[i][j]=fpack[i-1][j-ri[i]]+fpack[i-1][j];
			else
				fpack[i][j]+=fpack[i-1][j-ri[i]+f]+fpack[i-1][j];
			if (fpack[i][j]>=100000000)
				fpack[i][j]%=100000000;
		}
		
	}
	cout<<(fpack[n][0]-1)%100000000<<endl;
	return 0;
}
