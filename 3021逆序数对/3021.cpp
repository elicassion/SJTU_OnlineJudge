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
#include<set>
#include<map>
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
int n;
int v[3000011];
int a[3000011];
long long int CT=0;
void merge(int first,int mid,int last)
{

     int index,indexa,indexb;
     index=0;
     indexa=first;
     indexb=mid+1;
     while(indexa<=mid&&indexb<=last)
     {
           if(v[indexa]<v[indexb])
                a[index++]=v[indexa++];
           else
           {
               a[index++]=v[indexb++];
               CT=CT+mid-indexa+1;
           }

     }
     while(indexa<=mid)
          a[index++]=v[indexa++];
     while(indexb<=last)
          a[index++]=v[indexb++];
     for(int i=0;i<index;++i)
          v[first+i]=a[i];
}
void sort(int first,int last)
{
     int mid;
     if(first<last)
     {
            mid=(first+last)/2;
            sort(first,mid);
            sort(mid+1,last);
            merge(first,mid,last);
     }
}
void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;++i)
     {
         scanf("%d",&v[i]);
     }
}
int main()
{
    //freopen("3021.in","r",stdin);
    //freopen("qs.out","w",stdout);
    init();
    sort(1,n);
    cout<<CT<<endl;
}

