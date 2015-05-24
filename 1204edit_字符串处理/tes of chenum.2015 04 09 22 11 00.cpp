#include<iostream>
#include<cstring>
using namespace std;
bool chenum(string s) //检查字符串是否是数字 
{
	int sl=s.length();
	if (s[0]=='-' && sl==1)
		return 0;
	if (s[0]!='-')
	{
		for (int i=0;i<sl;++i)
		{
			if (s[i]<='0' && s[i]>='9')
				return 0;
		}
	}
	else
	{
		for (int i=1;i<sl;++i)
		{
			if (s[i]<='0' && s[i]>='9')
				return 0;
		}
	}
	for (int i=0;i<sl;++i)
	{
		if (s[i]=='0' && sl!=1)
			return 0;
	}
	if(s[1]=='-' && s[2]=='0')
		return 0; 
	return 1;
}
int main()
{
	string s="";
	while (s!="n")
	{
		cin>>s;
	}
	if (chenum(s))
		cout<<"OK"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
