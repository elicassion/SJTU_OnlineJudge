#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define FOR1(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
#define FOR2(i,x,y) for(int (i)=(x);(i)>=(y);(i)--)
using namespace std;
int f[1020000],g[1020000];
int n;
int t[1020000];
int b[1020000];
int c[1020000];
int ans=999999999;
int bsearch(int k[],int n,int a) 
{
    
    int l=1, r=n;
    while(l<=r) 
    {
        int mid = (l+r)/2;
        if( a >= k[mid] && a < k[mid+1] ) 
            return mid+1; // >&&<= 换为: >= && <
        else if( a < k[mid] ) 
           r = mid-1;
        else l = mid+1;
    }
    
}
int main()
{
	//freopen("1067.in","r",stdin);
	//freopen("1067.out","w",stdout);
	scanf("%d",&n);
	FOR1(i,1,n)
	{
		scanf("%d",&t[i]);
	}
	//shangsheng
	FOR1(i,1,n)
	{
		f[i]=1;
	}
	int j;
	int size =1;
	c[1]=a[1];
	FOR1(i,2,n)
	{
		if( a[i] < c[1] ) j = 1;// <= 换为: <
        else if( a[i] >=c[size] )
            j=++size;   // > 换为: >= 
        else 
            j = bsearch(c, size, a[i]);
        c[j] = a[i]; f[i] = j;
	}
	
	//xiajiang
	FOR1(i,1,n)
	{
		g[i]=1;
	}
	FOR2(i,n-1,1)
	{
		FOR2(j,n,i+1)
		{
			if(t[i]>t[j])
				g[i]=max(g[i],g[j]+1);
		}
	}
	f[0]=0;
	g[0]=0;
	f[n+1]=0;
	g[n+1]=0;
	FOR1(k,1,n)
	{
		if(ans>n-(f[k]+g[k]-1))
			ans=n-(f[k]+g[k]-1);
	}
	printf("%d\n",ans);
	return 0;
}