#include<string.h>
#include<iostream>
using namespace std;
int n;
int ct=0;
int cjf[30000];
int fz[30000];
int fm[30000];
bool val[60000];
void qs(int l,int r)
{
	int i,j,mid,t,s,q;
	i=l;j=r;mid=cjf[(i+j)/2];
	while(i<=j)
	{
		while(cjf[j]>mid) j--;
		while(cjf[i]<mid) i++;
		if(i<=j)
		{
			t=cjf[i];cjf[i]=cjf[j];cjf[j]=t;
			s=fz[i];fz[i]=fz[j];fz[j]=s;
			q=fm[i];fm[i]=fm[j];fm[j]=q;
			i++;j--;
		}
	}
	if(l<j) qs(l,j);
	if(i<r) qs(i,r);
}
void zc()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>=j) continue;
			int got=i*50880/j;
			if(!val[got])
			{
				ct++;
				cjf[ct]=got;
			    fz[ct]=i;
		        fm[ct]=j;
			    val[got]=1;
			}
			else continue;
		}
	}
}
void print()
{
	for(int i=1;i<=ct;i++)
		cout<<fz[i]<<'/'<<fm[i]<<'\n';
	cout<<'1'<<'/'<<'1'<<'\n';
}
int main()
{
	memset(cjf,0,sizeof(cjf));
	memset(fz,0,sizeof(fz));
	memset(fm,0,sizeof(fm));
	memset(val,0,sizeof(val));
	cin>>n;
	cout<<'0'<<'/'<<'1'<<'\n';
	zc();
	qs(1,ct);
	print();
	return 0;
}
