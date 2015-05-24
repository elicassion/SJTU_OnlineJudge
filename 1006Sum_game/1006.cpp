#include<iostream>
#include<cstdio>
using namespace std;
int a[1000010];
int n;
int mss(int l,int r)
{
    if (l==r-1)
        return max(0,a[l]+a[r]);
    else if(l==r)
        return max(0,a[l]);
    int mid=(l+r)>>1;
    int lsum=0,rsum=0;
    int lmx=mss(l,mid);
    int rmx=mss(mid+1,r);
    int ltmp=-0x7fffffff;
    int rtmp=-0x7fffffff;
    for (int i=mid;i>=l;--i)
    {
        lsum+=a[i];
        if (lsum>ltmp)
            ltmp=lsum;
    }
    for (int i=mid+1;i<=r;++i)
    {
        rsum+=a[i];
        if (rsum>rtmp)
            rtmp=rsum;
    }
    return max(0,max(max(rmx,ltmp+rtmp),lmx));
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    if (n==2)
    {
        if (a[1]+a[2]>0)
            cout<<a[1]+a[2]<<endl;
        else
            cout<<"Game Over"<<endl;
        return 0;
    }
    int ans=max(0,mss(1,n));
    if (ans==0)
        cout<<"Game Over"<<endl;
    else
        cout<<ans<<endl;
    return 0;

}
