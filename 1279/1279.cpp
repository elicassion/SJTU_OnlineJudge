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
char hsh[400];
int N;
//int hav_ct=0;
bool isR=false;
bool v[10000000]={0};
int ct[10000000]={0};
int main()
{
    //RFF("1279.in");
    //WFF("1279.out");
    /*for (int i=0;i<100010;++i)
    	a[i].ct=0;*/
	hsh['A']=hsh['B']=hsh['C']='2';
	hsh['D']=hsh['E']=hsh['F']='3';
	hsh['G']=hsh['H']=hsh['I']='4';
	hsh['J']=hsh['K']=hsh['L']='5';
	hsh['M']=hsh['N']=hsh['O']='6';
	hsh['P']=hsh['R']=hsh['S']='7';
	hsh['T']=hsh['U']=hsh['V']='8';
	hsh['W']=hsh['X']=hsh['Y']='9';
	//cout<<hsh['A']<<' '<<hsh['B']<<' '<<hsh['C']<<endl;
	cin>>N;
	for (int i=1;i<=N;++i)
	{
		char i_s[3000];
		scanf("%s",i_s);
		string s="";
		for (int j=0;j<strlen(i_s);++j)
		{
			if (i_s[j]=='-')
				continue;
			else if (i_s[j]>='A' && i_s[j]<='Z')
			{
				s+=hsh[i_s[j]];
			}
			else
				s+=i_s[j];
		}
		int t_s=0;
		for (int j=0;j<s.length();++j)
			t_s = t_s*10 + (s[j]-48);

		
		if (v[t_s])
		{
			++ct[t_s];
			isR = true;
		}
		else
		{
			v[t_s]=1;
			++ct[t_s];
		}
	}
	if (!isR)
	{
		cout<<"No duplicates."<<endl;
		return 0;
	}
	//sort(a+1,a+hav_ct+1,cmp);
	for (int i=1;i<=9999999;++i)
	{
		if (ct[i]>1)
		{
			printf("%03d-",i/10000);
			printf("%04d ",i%10000);
			printf("%d\n",ct[i]);
		}
	}
    return 0;
}
