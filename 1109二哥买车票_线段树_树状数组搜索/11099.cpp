#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
struct line
{
	int left,right;//×ó¶Ëµã¡¢ÓÒ¶Ë
};
line p[400002];
int n;
//int a[100001];
//int c[100001];
int sum[400002];
int col[400002]={0};
int add[400002]={0};
int pv[100001];
void PushUp(int v)
{
	sum[v] = sum[v*2] + sum[v*2+1];
}

void PushDown(int v,int m)
{
	if (col[v])
	{
		col[v<<1] = col[v<<1|1] = col[v];
		sum[v<<1] = (m - (m >> 1)) * col[v];
		sum[v<<1|1] = (m >> 1) * col[v];
		col[v] = 0;
	}
}

void updates(int L,int R,int c,int l,int r,int v)
{
	if (L <= l && r <= R)
	{
		col[rt] = c;
		sum[rt] = c * (r - l + 1);
		return ;
	}
	PushDown(v , r - l + 1);
	int m = (l + r)/2;
	if (L <= m) updates(L , R , c , l,m,v*2);
	if (R > m) updates(L , R , c , m+1,r,v*2+1);
	PushUp(v);
}

void updatea(int L,int R,int c,int l,int r,int v)
{
	if (L <= l && r <= R)
	{
		add[v] += c;
		sum[v] += c * (r - l + 1);
		return;
	}
	PushDown(v , r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) updatea(L , R , c , l,m,v*2);
	if (m < R) updatea(L , R , c , m+1,r,v*2+1);
	PushUp(v);
}


int query(int L,int R,int l,int r,int v)
{
	if (L <= l && r <= R)
	{
		return sum[v];
	}
	PushDown(v , r - l + 1);
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret += query(L , R , l,m,v*2);
	if (m < R) ret += query(L , R , m+1,r,v*2+1);
	return ret;
}

void build(int s,int t,int v)
{
	if (s==t)
	{
		sum[v]=1;
		pv[s]=v;
		return;
	}
	int mid=(s+t)/2;
	p[v].left=s;
	p[v].right=t;
	build(s,mid,2*v);
	build(mid+1,t,2*v+1);
	PushUp(v)
}

int main()
{
	freopen("1109.in","r",stdin);
	freopen("1109.out","w",stdout);
	cin>>n;
	build(1,n,1);
	int a,c;
	for (int i=1;i<=n;++i)
	{
		cin>>a>>c;
		int k=min(p[pv[a]],n-c);
		
		
	}
} 
