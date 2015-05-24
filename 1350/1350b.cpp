#include<iostream>
using namespace std;
int x[800];
int y[800];
int maxct=-0x7fffffff;
int n;
inline float sk(int a,int b)
{
    return (y[b]-y[a])*1.0/(x[b]-x[a]);
}
void qs(float k[],int l,int r)
{
     int i,j;
     float mid,t;
     i=l;j=r;mid=k[(i+j)/2];
     while(i<=j)
     {
           while(k[j]>mid) j--;
           while(k[i]<mid) i++;
           if(i<=j)
           {
                   t=k[i];k[i]=k[j];k[j]=t;
                   i++;j--;
           }
     }
     if(l<j) qs(k,l,j);
     if(i<r) qs(k,i,r);
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x[i]>>y[i];
    }
    if (n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    else if (n==2)
    {
        cout<<2<<endl;
        return 0;
    }
    for (int i=1;i<=n;++i)
    {
        float k[800];
        int ct=0;
        for (int j=i+1;j<=n;++j)
            //if (i!=j)
                k[++ct]=sk(i,j);
        qs(k,1,ct);
        int tmpct=1;
        k[0]=0x7fffffff;
        for (int j=1;j<=ct;++j)
        {
            if (k[j]==k[j-1])
                tmpct++;
            else
            {
                if (tmpct > maxct)
                    maxct=tmpct;
                tmpct=1;
            }
        }
        if (tmpct > maxct)
                maxct=tmpct;
    }
    cout<<maxct+1<<endl;
}
