#include<stdio.h>
int n;
int a[100001];
void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;++i)
         scanf("%d",&a[i]);
}
void qs(int l,int r)
{
     int i,j,mid,t;
     i=l;j=r;mid=a[(i+j)/2];
     while(i<=j)
     {
           while(a[j]>mid) j--;
           while(a[i]<mid) i++;
           if(i<=j)
           {
                   t=a[i];a[i]=a[j];a[j]=t;
                   i++;j--;
           }
     }
     if(l<j) qs(l,j);
     if(i<r) qs(i,r);
}
int main()
{
    //freopen("qs.in","r",stdin);
    //freopen("qs.out","w",stdout);
    init();
    qs(1,n);
    for(int i=1;i<=n;++i)
        printf("%d ",a[i]);
}
