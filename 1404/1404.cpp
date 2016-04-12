#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>
#define RFF(s) freopen(s,"r",stdin)
#define WFF(s) freopen(s,"w",stdout)
using namespace std;
string hero[10000];
int ct_hero=0;
string pbufh[10000];
int ct_pbufh=0;
int maxnord=-0x7fffffff;
int ct_kill=0;
int stoi(string s)
{
	//cout<<"s: "<<s<<' ';
	int x=0;
	for (int i=0;i<s.length();++i)
	{
		x=x*10+(s[i]-48);
	}
	//cout<<x<<endl;
	return x;
}
void addhero(string s)
{
	//cout<<s<<endl;
	while (s[s.length()-1]=='.' || s[s.length()-1]=='!' || s[s.length()-1]==' ' || s[s.length()-1]=='\n')
		s.erase(s.length()-1,1);
	for (int i=1;i<=ct_hero;++i)
	{
		if (hero[i]==s)
			return;
	}
	hero[++ct_hero]=s;
}
void addpbufh(string s)
{
	//cout<<s<<endl;
	while (s[s.length()-1]=='.' || s[s.length()-1]=='!' || s[s.length()-1]==' ' || s[s.length()-1]=='\n')
		s.erase(s.length()-1,1);
	for (int i=1;i<=ct_pbufh;++i)
	{
		if (pbufh[i]==s)
			return;
	}
	pbufh[++ct_pbufh]=s;
}
void print()
{
	printf("#1:\n");
	printf("%d\n",ct_hero);

	printf("#2:\n");
	if (maxnord>0)
		printf("%d\n",maxnord);
	else
		printf("-1\n");

	printf("#3:\n");
	printf("%d\n",ct_kill);

	printf("#4:\n");
	if (ct_pbufh==0)
		printf("-1\n");
	else
	{
		for (int i=1;i<=ct_pbufh;++i)
		{
			cout<<pbufh[i]<<endl;
		}
	}

}
void doit(string s)
{
	int x;
	s.erase(0,s.find_first_of(" ")+1); 
	if (s.find(" hits ")!=-1 && s.find(" for ")!=-1 && s.find(" with ")==-1)
	{
		int hp = s.find(" hits ");
		int fp = s.find(" for ");
		addhero(s.substr(0,hp ) );
		addhero(s.substr(hp+6, fp-(hp+6) ) );
		int dp = s.find(" damage");
		int nord = stoi(s.substr(fp+5, dp-(fp+5) ) );
		if (nord>maxnord)
			maxnord = nord;
	}
	else if (s.find(" hits ")!=-1 && s.find( " with " )!=-1 )
	{
		int hp = s.find(" hits ");
		int wp = s.find(" with ");
		addhero(s.substr(0,hp ) );
		addhero(s.substr(hp+6, wp-(hp+6) ) ); 
	}
	else if (s.find(" receives ")!=-1 && s.find(" buff from")!=-1 )
	{
		int rp = s.find(" receives ");
		addhero(s.substr(0,rp));
		int fp = s.find(" from ");
		addhero(s.substr(fp+6,s.length()-1-(fp+6)));
		addpbufh(s.substr(fp+6,s.length()-1-(fp+6)));
	}
	else if (s.find(" receives ")!=-1 && s.find(" debuff from ")!=-1)
	{
		int rp = s.find(" receives ");
		addhero(s.substr(0,rp));
		int fp = s.find(" from ");
		addhero(s.substr(fp+6,s.length()-1-(fp+6)));
	}
	else if (s.find(" loses ")!=-1)
	{
		int lp = s.find(" loses ");
		addhero(s.substr(0,lp));
	}
	else if (s.find(" is killed by ")!=-1)
	{
		int ip = s.find(" is ");
		int bp = s.find(" by ");
		addhero(s.substr(0,ip));
		addhero(s.substr(bp+4,s.length()-1-(bp+4)));
		++ct_kill;
	}
}
int main()
{
    //RFF("1404.in");
    //WFF("1404.out");
    string s;
    while (getline(cin,s))
    {
    	if (s=="#DOTA2#")
    	{
    		print();
    		return 0;
    	}
    	while (s==""||s=="\n")
    		getline(cin,s);
    	doit(s);
    }
    return 0;
}
