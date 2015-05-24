#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	//freopen("1004.in","r",stdin);
	//freopen("1004.out","w",stdout);
	int m,t,u,f,d;
	cin>>m>>t>>u>>f>>d;
	int sum=0;
	for (int i=1;i<=t;++i)
	{
		char c;
		cin>>c;
		if (c=='u' || c=='d')
		{
			if (sum+u+d>m)
			{
				cout<<i-1<<endl; 
				return 0;
			}
			else
				sum+=u+d;
		}
		else
		{
			if (sum+2*f>m)
			{
				cout<<i-1<<endl;
				return 0;
			}
			else
				sum+=2*f;
		}	
	}
	cout<<t<<endl;
	
	return 0;
} 
