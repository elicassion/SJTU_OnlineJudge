#include<iostream>
#include<stdio.h>
using namespace std;
int sum[1001][1001];
int ssum[1001];
int l,w;
int map[1001][1001];
int main()
{
	//freopen("1002.in","r",stdin);
	//freopen("1002.out","w",stdout);
	scanf("%d %d",&l,&w);
	for(int i=1;i<=l;++i)
	{
		for(int j=1;j<=w;++j)
		{
			scanf("%d",&map[i][j]);
		}
	}
	int a,b;
	scanf("%d %d",&a,&b);


	for(int m=1;m<=w;++m)
	{
		sum[m][1]=0;
		for(int i=1;i<=a;++i)
			sum[m][1]+=map[i][m];
		for(int i=2;i<=l-a+1;++i)
			sum[m][i]=sum[m][i-1]-map[i-1][m]+map[i+a-1][m];
	}
	int maxn=-0x7ffffff;
	for(int m=1;m<=l-a+1;++m)
	{
		ssum[1]=0;
		for(int i=1;i<=b;++i)
			ssum[1]+=sum[i][m];
		if(ssum[1]>maxn)
			maxn=ssum[1];
		for(int i=2;i<=w-b+1;++i)
		{
			ssum[i]=ssum[i-1]-sum[i-1][m]+sum[i+b-1][m];
			if(ssum[i]>maxn)
				maxn=ssum[i];
		}
	}
	printf("%d",maxn);
	return 0;
}
