#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std; 
int n,m,s,t;
short a[10001],b[10001],c[10001],d[10001],e[10001],path[10002],dist[10001],que[10001];
bool vi[1001];
int s2i(string s)
{
	
}
void init()
{
     memset(vi,0,sizeof(vi));
     memset(path,0,sizeof(path));
     cin>>n>>m>>s>>t;
     getchar();
     string des;
     for(int i=1;i<=m;++i)
    {
    	getline(cin,des);
    	int ia=des.find("From: ");
    	int ib=des.find("To: ");
		int ic=des.find("Length: ");
		int id=des.find("People number: ");
		int ie=des.find("Light: ");
		int ig=des.find(";");
		string iaa=des.substr(ia+6,ib-ia-8);
		a[i]=
		string ibb=des
    }
     for(int i=1;i<=n;++i)
         dist[i]=0x7fffffff;    
}
void qs(int l,int r)
{
     int i,j,mid,t;
     i=l;
     j=r;
     mid=a[(i+j)/2];
     while(i<=j)
     {
           while(a[j]>mid) j--;
           while(a[i]<mid) i++;
           if(i<=j)
           {
                   t=a[i];a[i]=a[j];a[j]=t;
                   t=b[i];b[i]=b[j];b[j]=t;
                   t=c[i];c[i]=c[j];c[j]=t;
                   i++;j--;
           }
     }
     if(i<r) qs(i,r);
     if(j>l) qs(l,j);
}
void spfa(int v0)
{
     int h,t,now,next;
     h=1;t=2;
     dist[v0]=0;
     que[h]=v0;
     vi[v0]=true;
     while(h!=t)
     {
           now=que[h];
           for(int i=path[now];i<=path[now+1]-1;i++)
           {
                next=b[i];
                if(dist[now]+c[i]<dist[next])
                {
                     dist[next]=dist[now]+c[i];
                     if(!vi[next])
                     {
                          vi[next]=true;        
                          que[t]=next;
                          t++;if(t>100) t=1;        
                     }
                }   
           }
           vi[now]=false;
           h++;if(h>100) h=1;     
     }
}
int main()
{
    freopen("1105.in","r",stdin);
    freopen("1105.out","w",stdout);
    int tt;
	cin>>tt;
	for (int gro=1;gro<=tt;++gro)
	{
    	init();
    	qs(1,m);
    	path[1]=1;path[n+1]=m+1;
    	for(int i=1;i<=m;++i)
        	if(path[a[i]]==0) path[a[i]]=i;
    	for(int i=n;i>=1;--i)
        	if(path[i]==0) path[i]=path[i+1];
    	spfa(1);
    	for(int i=1;i<=n;++i)
        	printf("%d ",dist[i]);
	}
}

