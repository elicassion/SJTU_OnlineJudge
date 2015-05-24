#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
	//freopen("1133.in","r",stdin);
	//freopen("1133.out","w",stdout);
	
	string sen;
	cin>>sen;
	int l=sen.length();
	long long int s=0,t=0,a=0,r=0;
	int ss=0,tt=0,aa=0,rr=0;
	int gou=0;
	long long int zhuren=0;
	
	for (int i=0;i<l;++i)
	{
		if (sen[i] == 'S')
		{
			s++;
			ss++;
		}
		if (sen[i] == 'T')
		{
			t++;
			if (tt+1 <= ss)
			{
				tt++;
			}
		}
		if (sen[i] == 'A')
		{
			a++;
			if (aa+1 <= tt)
			{
				aa++;
			}
		}
		if (sen[i] == 'R')
		{
			r++;
			if (rr+1 <= aa)
			{
				rr++;
			}
		}
	}
	
	
	
	
	zhuren=s*t*a*r;
	gou=min(min(min(s,t),a),r);
	cout<<zhuren<<' '<<gou<<' '<<rr<<endl;
	
	
}
