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
	int di,dj,num;
	cin>>di>>dj>>num;
	s="";
	for (int i=0;i<dj-1;++i)
		s+=p[di][i];
	for (int i=dj+num-1;i<p[di].length();++i)
		s+=p[di][i];
	p[di]=s;
	cout<<p[di]<<endl;
}
