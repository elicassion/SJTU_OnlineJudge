#include<iostream>
#include<cstring>
using namespace std;
string p[100001];
int pl=0;
int l[100001]={0};
bool chenum(string s)
{
	
}
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
	string sub[4];
	for (int i=0;i<=3;++i)
		sub[i]="";
	for (int i=0;i<f[4];++i)
	{
		for (int j=f[i]+1;j<=f[i+1];++j)
		{
			sub[i]+=s[j];
		}
	}
	for (int i=f[f[4]]+1;i<sl;++i)
		sub[3]+=s[i];
	// sub代表截出来的字串 sub[0]是操作 sub[1]是第一个参数 list的第二个参数在sub[3]中 sub[2]是第二个参数 sub[3]是第三个参数 
	// 传参数记得去空格 
	if (sub[0]=="list ")
		lis(sub[1],sub[3]); 
	else if (sub[0]="ins ")
		ins(sub[1],sub)
	
}
void ins()
{
	
}
void del()
{
	
}
void lis()
{
	
}
int main()
{
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
