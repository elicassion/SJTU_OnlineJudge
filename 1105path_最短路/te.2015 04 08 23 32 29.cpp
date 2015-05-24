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
		string iaa=des.substr(ia+6,ib-ia-8);
		a[i]=s2i(iaa);
		string ibb=des.substr(ib+4,ic-ib-6);
		b[i]=s2i(ibb);
		string icc=des.substr(ic+8,id-ic-10);
		c[i]=s2i(icc);
		string idd=des.substr(id+15,ie-id-17);
		d[i]=s2i(idd);
		string iee=des.substr(ie+7,ig-ie-7);
		e[i]=s2i(iee);
		cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<' '<<d[i]<<' '<<e[i]<<endl;
    }
    return 0;
}
