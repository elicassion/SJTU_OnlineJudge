#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define FOR(i,bg,ed) for(int i=bg;i<=ed;++i)
#define RFOR(i,bg,ed) for(int i=bg;i>=ed;--i)
#define MSET(a,i) memset(a,i,sizeof(a))
#define CIa1(a,i) cin>>a[i]
#define CIa2(a,i,j) cin>>a[i][j]
#define COa1(a,i) cout<<a[i]<<' '
#define COa2(a,i,j) cout<<a[i][j]<<' '
#define SCIa1(a,i) scanf("%d",&a[i])
#define SCIa2(a,i,j) scanf("%d",&a[i][j])
#define SCOa1(a,i) printf("%d ",a[i])
#define SCOa2(a,i,j) printf("%d ",a[i][j])
#define RFF(s) freopen(s,"r",stdin)
#define WFF(s) freopen(s,"w",stdout)
#define MOL 1000000009
//��״�����õ�ʱ��ȡ���ǰ�����λ��֮ǰλ���еĺ͡�
//���ʱ�򲢷�����
using namespace std;
int a[1000010];
int f[1000010]={0};
int pa[1000010]={0};
int da[1000010];
int N;
int ct=0;
inline int lowbit(int v)
{
    return v&(-v);
}
inline int getsum(int v)
{
	int sum=0;
	for (int i=v; i>=1;i-=lowbit(i))
		sum=(sum+f[i])%MOL;
	return sum;
}
inline void update(int v, int value)
{
	for (int i=v;i<=ct;i+=lowbit(i))
		f[i]=(f[i]+value)%MOL;
}
inline int fd(int key)
{
	FOR(i,1,ct)
	{
	    if (da[i]>=key)
            return i;
	}
	//return lower_bound(da,da+ct,key)-da+1;
}
int main()
{
    //RFF("1289.in");
    //WFF("t.out");
    scanf("%d",&N);
    FOR(i,1,N)
    {
        SCIa1(a,i);
        pa[i]=pa[i-1]+a[i];
    }
    sort(pa,pa+N+1);
    da[0]=pa[0];
    FOR(i,1,N)
    {
        if (pa[i]!=da[ct])
            da[++ct]=pa[i];
    }
    ct++;
    //��������˲�ȡ���ֵ�0ǰ׺�͵��������˹�N+1��
    update(fd(0),1);
    int ans=0;
    int csum=0;
    FOR(i,1,N)
    {
        csum+=a[i];
        int v=fd(csum);
        ans=getsum(v);
        update(v,ans);
    }
    cout<<ans<<endl;
    return 0;
}
