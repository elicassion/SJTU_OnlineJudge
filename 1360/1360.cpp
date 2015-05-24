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
#include<queue>
#include<stack>
#include<list>
#include<vector>
#define FOR(i,bg,ed) for(int i=bg;i<=ed;++i)
#define RFOR(i,bg,ed) for(int i=bg;i>=ed;--i)
#define FOR_S(i,bg,ed,step) for(int i=bg;i<=ed;i+=step)
#define RFOR_S(i,bg,ed,step) for(int i=bg;i>=ed;i-=step)
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
#define LL long long int
#define SPACE printf(" ")
#define ENTER printf("\n")
using namespace std;
int t1[100010]={0};
int t2[100010]={0};
int CT=0;
int N;
void qs(int l,int r,int a[],int b[])
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
                   t=b[i];b[i]=b[j];b[j]=t;
                   i++;j--;
           }
     }
     if(l<j) qs(l,j,a,b);
     if(i<r) qs(i,r,a,b);
}
int main()
{
    //RFF("1360.in");
    //WFF("t.out");
    cin>>N;
    FOR(i,1,N)
    {
        SCIa1(t1,i);
        SCIa1(t2,i);
    }
    qs(1,N,t2,t1);
    int ed=0;
    FOR(i,1,N)
    {
        if (t1[i]>=ed)
        {
            CT++;
            ed=t2[i];
        }
    }
    cout<<CT<<endl;
    return 0;
}
