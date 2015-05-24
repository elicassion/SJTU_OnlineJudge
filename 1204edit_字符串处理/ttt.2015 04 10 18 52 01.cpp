#include<cstring>
#include<iostream>
#include<stdio.h>
using namespace std;
string p[102];
int pl=0;
int main()
{
	freopen("1204.in","r",stdin);
	//freopen("1204.out","w",stdout); 
	string s="";
	while (s!="******")
	{
		getline(cin,s);
		p[++pl]=s;
	}
	pl--;
	int di,dj;
	string s3;
	cin>>di>>dj>>s3;
	int insl=s3.length();
	int rl=p[di].length();
	cout<<insl<<' '<<rl<<endl;
	for (int i=rl-insl;i<rl;++i)
		p[di]+=p[di][i];
	for (int i=rl-1-insl;i>=dj;--i)
		p[di][i+insl]=p[di][i];
	for (int i=0;i<insl;++i)
		p[di][dj+i-1]=s3[i];
	cout<<p[di]<<endl;
}
