#include<iostream>
using namespace std;
int main()
{
	int a,b,n;
	cin>>a>>b>>n;
	int ct;
	ct=0;
	int c=a+b;
	int d;
	for(int i=1;i<=n;i++)
	{
		cin>>d;
		if(c>=d)
		{
			ct++;
		}
	}
	cout<<ct<<endl;
	return 0;
}

