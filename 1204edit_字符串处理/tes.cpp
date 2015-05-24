#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
string p[100001];
int pl=0;
int l[100001]={0};
void check(string s)
{
	int sl=s.length();
	if (s=="quit")
		return;
	if (sl<8)
	{
		cout<<"Error!\n";
		return;
	}	
	int f[5]={-1,-1,-1,-1,0};
	for (int i=0;i<sl;++i)
	{
		if (s[i]==' ')
			f[++f[4]]=i;
		if (f[4]==3)
			break;
	}
	cout<<"f: ";
	for (int i=0;i<=4;++i)
		cout<<f[i]<<' ';
	cout<<endl;
	string sub[5];
	for (int i=0;i<=4;++i)
		sub[i]="";
	for (int i=0;i<f[4];++i)
	{
		for (int j=f[i]+1;j<f[i+1];++j)
		{
			sub[i]+=s[j];
		}
	}
	for (int i=f[f[4]]+1;i<sl;++i)
		sub[3]+=s[i];
	for (int ct=1;ct<=3;++ct)
	{
		for (int i=0;i<=3;++i)
		{
			if (sub[i]=="")
			{
				int k=i;
				while (k<4)
				{
					sub[k]=sub[k+1];
					k++;
				}
			}
		}
	}
	for (int i=0;i<=3;++i)
		cout<<sub[i]<<"-FUCK"<<endl;
	cout<<"-------------"<<endl;
}

int main()
{
	freopen("1204.in","r",stdin);
	//freopen("1204.out","w",stdout); 
	string s="";
	while (s!="******")
	{
		getline(cin,s);
		p[++pl]=s;
		l[pl]=s.length();
	}
	
	while (s!="quit")
	{
		getline(cin,s);
		check(s);
	}
	return 0;
}
