#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int a[100010],b[100010];
int n;
int mxs[18]={0};
int mis[18]={0};
void gjj(int p[],long long int k)
{
    int q[18]={0};
    while (k!=0)
    {
        q[++q[0]]=k%10;
        k=k/10;
    }
    for (int i=1;i<=q[0];++i)
        p[i]+=q[i];
    for (int i=1;i<=17;++i)
    {
        if (p[i]>=10)
        {
            p[i+1]+=p[i]/10;
            p[i]%=10;
        }
    }
}
void prt(int p[])
{
    int mk=17;
    while (p[mk]==0)
        mk--;
    for (int i=mk;i>=1;i--)
        cout<<p[i];
}
void qsa(int l,int r)
{
    int i=l,j=r,t,mid=a[(l+r)/2];
    while (i<=j)
    {
        while (a[i]<mid) i++;
        while (a[j]>mid) j--;
        if (i<=j)
        {
            t=a[i];a[i]=a[j];a[j]=t;
            i++;j--;
        }
    }
    if (l<j) qsa(l,j);
    if (i<r) qsa(i,r);
}
void qsb(int l,int r)
{
    int i=l,j=r,t,mid=b[(l+r)/2];
    while (i<=j)
    {
        while (b[i]<mid) i++;
        while (b[j]>mid) j--;
        if (i<=j)
        {
            t=b[i];b[i]=b[j];b[j]=t;
            i++;j--;
        }
    }
    if (l<j) qsb(l,j);
    if (i<r) qsb(i,r);
}
int main()
{
    //freopen("1338.in","r",stdin);
    //freopen("1338.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;++i)
        scanf("%d",&b[i]);
    qsa(1,n);
    qsb(1,n);
    for (int i=1;i<=n;++i)
    {
        long long int k=a[i];
        k*=b[i];
        gjj(mxs,k);
    }
    for (int i=1;i<=n;++i)
    {
        long long int k=a[i];
        k*=b[n-i+1];
        gjj(mis,k);
    }
    prt(mxs);
    cout<<' ';
    prt(mis);
    return 0;
}
