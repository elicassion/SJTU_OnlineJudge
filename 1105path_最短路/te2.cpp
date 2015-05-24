#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int a[10001],b[10001],c[10001],d[10001],e[10001],path[10002],dist[10001],que[10001];
int n,m,s,t; 
int s2i(string s)
{
	short k=0;
	int l=s.length();
	for (int i=0;i<l;++i)
	{
		k=k*10+s[i]-'0';
	}
	return k;
}
int main()
{
	freopen("1105.in","r",stdin);
    freopen("1105.out","w",stdout);
	int tt;
	cin>>tt;
	cin>>n>>m>>s>>t;
    getchar();
    string des;
    for(int i=1;i<=m;++i)
    {
    	getline(cin,des);
    	int ia=des.find("From: ");
    	int ib=des.find("To: ");
		int ic=des.find("Length: ");
		int id=des.find("People number: ");
		int ie=des.find("Light: ");
		int ig=des.find(";");
		string iaa="";
		for (int j=ia+6;j<ib-2;++j)
		    iaa+=des[j];
		a[i]=s2i(iaa);
		string ibb="";
		for (int j=ib+4;j<ic-2;++j)
			ibb+=des[j];
		b[i]=s2i(ibb);
		string icc="";
		for (int j=ic+8;j<id-2;++j)
			icc+=des[j];
		c[i]=s2i(icc);
		string idd="";
		for (int j=id+15;j<ie-2;++j)
			idd+=des[j];
		d[i]=s2i(idd);
		string iee="";
		for (int j=ie+7;j<ig;++j)
			iee+=des[j];
		e[i]=s2i(iee);
		cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<' '<<d[i]<<' '<<e[i]<<endl;
    }
    return 0;
}
