#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
string p[100001];
int pl=0;
int l[100001]={0};
bool chenum(string s) //检查字符串是否是数字 
{
	int sl=s.length();
	if (s=="")
		return 0;
	if (s[0]=='-' && sl==1)
		return 0;
	if (s[0]!='-')
	{
		for (int i=0;i<sl;++i)
		{
			if (s[i]<'0' || s[i]>'9')
				return 0;
		}
	}
	else
	{
		for (int i=1;i<sl;++i)
		{
			if (s[i]<'0' || s[i]>'9')
				return 0;
		}
	}
	
	if(s[0]=='0' && sl>1)
	if(s[0]=='-' && s[1]=='0')
		return 0; 
	return 1;
}
int s2i(string s)
{
	int sl=s.length();
	if (s[0]=='-')
	{
		int k=0;
		for (int i=1;i<sl;++i)
		{
			k=k*10+s[i]-'0';
		}
		return k*(-1);
	}
	else
	{
		int k=0;
		for (int i=0;i<sl;++i)
		{
			k=k*10+s[i]-'0';
		}
		return k;
	}
}

void ins(string s1,string s2,string s3)
{
	if (chenum(s1) && chenum(s2))
	{
		int di=s2i(s1);
		int dj=s2i(s2);
		if (di>=1 && di<=pl)
		{
			if (dj>=1 && dj<=p[di].length()+1 && s3!="")
			{
				if (dj<=p[di].length())
				{
					int insl=s3.length();
					int rl=p[di].length();
					for (int i=rl-insl;i<rl;++i)
						p[di]+=p[di][i];
					for (int i=rl-1;i>=dj;--i)
						p[di][i+insl]=p[di][i];
					for (int i=0;i<insl;++i)
						p[di][dj+i-1]=s3[i];
					return;
				}
				else
					p[di]+=s3;	
			}
		}
	}
	cout<<"Error!"<<endl;
}
void del(string s1,string s2,string s3)
{
	if (chenum(s1) && chenum(s2) && chenum(s3))
	{
		int di=s2i(s1);
		int dj=s2i(s2);
		int num=s2i(s3);
		if (di>=1 && di<=pl)
		{
			if (dj>=1 && dj<=p[di].length() && num>=0)
			{
				for (int i=dj+num-1;i<p[di].length();++i)
				{
					p[di][i-num]=p[di][i];
				}
				p[di][p[di].length()-num]='\0';
				return;
			}
		}
	}
	cout<<"Error!"<<endl;
}
void lis(string sp,string ep)
{	
	if (chenum(sp) && chenum(ep))
	{
		int s=s2i(sp);
		int e=s2i(ep);
		if (s>=1 && s<=pl && e>=s && e<=pl)
		{
			for (int i=s;i<=e;++i)
				cout<<p[i]<<endl;
			return;
		}
	}
	cout<<"Error!"<<endl;
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
		for (int j=f[i]+1;j<f[i+1];++j)
		{
			sub[i]+=s[j];
		}
	}
	for (int i=f[f[4]]+1;i<sl;++i)
		sub[3]+=s[i];
	// sub代表截出来的字串 sub[0]是操作 sub[1]是第一个参数 list的第二个参数在sub[3]中 sub[2]是第二个参数 sub[3]是第三个参数 
	if (sub[0]=="list")
		lis(sub[1],sub[3]); 
	else if (sub[0]=="ins")
		ins(sub[1],sub[2],sub[3]);
	else if (sub[0]=="del")
		del(sub[1],sub[2],sub[3]);
}
	

int main()
{
	//freopen("1204.in","r",stdin);
	//freopen("1204.out","w",stdout); 
	string s="";
	while (s!="******")
	{
		getline(cin,s);
		p[++pl]=s;
		l[pl]=s.length();
	}
	pl--;
	while (s!="quit")
	{
		getline(cin,s);
		check(s);
		if (s=="quit")
		{
			for (int i=1;i<=pl;++i)
				cout<<p[i]<<endl;
		}
	}
	return 0;
}
