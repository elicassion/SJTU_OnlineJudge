#include<cstring>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string b[101];
	getchar();
	for (int i=1;i<=n;++i)
		getline(cin,b[i]);
	int x,y;
	for (int i=1;i<=n-1;++i)
	{
		cin>>x>>y;
		b[y]=b[y]+" "+b[x];
		b[x]="";
	}
	cout<<b[y]<<endl;
}
