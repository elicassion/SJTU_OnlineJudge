#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std; 
int n,m;
short s,t;
short a[10002],b[10002],c[10002],d[10002],e[10002],path[10003],que[10002];
int dist[10002];
bool vi[1002];
short s2i(string s)
{
	short k=0;
	int l=s.length();
	for (int i=0;i<l;++i)
	{
		k=k*10+s[i]-'0';
	}
	return k;
}
void init()
{
     memset(vi,0,sizeof(vi));
     memset(path,0,sizeof(path));
     cin>>n>>m>>s>>t;
     //cout<<"n: "<<n<<' '<<"m: "<<m<<' '<<"s: "<<s<<' '<<"t: "<<t<<endl;
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
		a[i]=s2i(iaa);
		string ibb=des.substr(ib+4,ic-ib-6);
		b[i]=s2i(ibb);
		string icc=des.substr(ic+8,id-ic-10);
		c[i]=s2i(icc);
		string idd=des.substr(id+15,ie-id-17);
		d[i]=s2i(idd);
		string iee=des.substr(ie+7,ig-ie-7);
		e[i]=s2i(iee);
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
                   t=d[i];d[i]=d[j];d[j]=t;
                   t=e[i];e[i]=e[j];e[j]=t;
                   i++;j--;
           }
     }
     if(i<r) qs(i,r);
     if(j>l) qs(l,j);
}
void spfac(short v0)
{
     int h,t;
	 short now,next;
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
                          t++;if(t>10000) t=1;        
                     }
                }   
           }
           vi[now]=false;
           h++;if(h>10000) h=1;     
     }
}
void spfad(short v0)
{
     int h,t;
	 short now,next;
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
                if(dist[now]+d[i]<dist[next])
                {
                     dist[next]=dist[now]+d[i];
                     if(!vi[next])
                     {
                          vi[next]=true;        
                          que[t]=next;
                          t++;if(t>10000) t=1;        
                     }
                }   
           }
           vi[now]=false;
           h++;if(h>10000) h=1;     
     }
}
void spfae(short v0)
{
     int h,t;
	 short now,next;
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
                if(dist[now]+e[i]<dist[next])
                {
                     dist[next]=dist[now]+e[i];
                     if(!vi[next])
                     {
                          vi[next]=true;        
                          que[t]=next;
                          t++;if(t>10000) t=1;        
                     }
                }   
           }
           vi[now]=false;
           h++;if(h>10000) h=1;     
     }
}
int main()
{
    //freopen("1105.in","r",stdin);
    //freopen("1105.out","w",stdout);
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
    	spfac(s);
    	cout<<dist[t]<<' ';
    	memset(vi,0,sizeof(vi));
    	for(int i=1;i<=n;++i)
         dist[i]=0x7fffffff;
    	spfad(s);
    	cout<<dist[t]<<' ';
    	memset(vi,0,sizeof(vi));
    	for(int i=1;i<=n;++i)
         dist[i]=0x7fffffff;
    	spfae(s);
    	cout<<dist[t]<<' ';
    	cout<<endl;
	}
}

