#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#define F_(i,bg,ed) for(int i=bg;i<=ed;++i)
#define CI_a1(a,i) cin>>a[i]
#define CI_a1(a,i,j) cin>>a[i][j]
#define CO_a1(a,i) cout<<a[i]
#define CO_a2(a,i,j) cout<<a[i][j]
#define RFF(s) freopen(s,"r",stdin)
#define WFF(s) freopen(s,"w",stdout)
#define ED 500000
using namespace std;
//int fvi[1010];
int vi[1010]={0};
int v[1010]={0};
bool xi[1010][1010];
bool p[500010]={0};
int a[1010];
int T;
int N;
void qs1(int aa[],int l,int r)
{
     int i,j,mid,t;
     i=l;j=r;mid=aa[(i+j)/2];
     while(i<=j)
     {
           while(aa[j]<mid) j--;
           while(aa[i]>mid) i++;
           if(i<=j)
           {
                   t=aa[i];aa[i]=aa[j];aa[j]=t;
                   i++;j--;
           }
     }
     if(l<j) qs1(aa,l,j);
     if(i<r) qs1(aa,i,r);
}

void qs2(int aa[],int l,int r)
{
     int i,j,mid,t;
     i=l;j=r;mid=aa[(i+j)/2];
     while(i<=j)
     {
           while(aa[j]<mid) j--;
           while(aa[i]>mid) i++;
           if(i<=j)
           {
                   t=aa[i];aa[i]=aa[j];aa[j]=t;
                   t=vi[i];vi[i]=vi[j];vi[j]=t;
                   i++;j--;
           }
     }
     if(l<j) qs2(aa,l,j);
     if(i<r) qs2(aa,i,r);
}

void prime()
{
	int h=2;
	for(;h<=ED;)
	{
		if(p[h]){ h++;continue;}
		if(!p[h])
		{
			int k=2*h;
			for(;k<=ED;)
			{
				p[k]=1;
				k+=h;
			}
			h++;
	    }
	}
}

int main()
{
    //RFF("t.in");
    //WFF("t.out");
    prime();
    cin>>T;
    F_(ti,1,T)
    {
        memset(v,0,sizeof(v));
        memset(vi,0,sizeof(vi));
        memset(xi,0,sizeof(xi));
        cin>>N;
        F_(i,1,N)
            cin>>a[i];
        qs1(a,1,N);
        F_(i,1,N)
            vi[i]=i;

        F_(i,1,N)
        {
            F_(j,i+1,N)
            {
                if (a[i]%a[j]!=0)
                    continue;
                else if (p[a[i]/a[j]])
                    continue;
                else
                {
                    v[i]++;
                    v[j]++;
                    xi[i][j]=1;
                    xi[j][i]=1;
                }
            }
        }

        /*F_(i,1,N)
        {
            F_(j,1,v[i])
            {
                CO_a2(xi,i,j)<<' ';
            }
            cout<<endl;
        }*/

        qs2(v,1,N);

        /*F_(i,1,N)
            CO_a1(a,vi[i])<<' ';
        cout<<endl;*/

        int ans=N;
        F_(i,1,N)
        {
            /*F_(j,i,N)
                CO_a1(v,j)<<' ';
            cout<<endl;*/

            if (v[i]==0)
                break;
            F_(j,1,N)
            {
                if (xi[vi[i]][vi[j]])
                {
                    xi[vi[i]][vi[j]]=0;
                    xi[vi[j]][vi[i]]=0;
                    v[j]--;
                }
            }
            qs2(v,i+1,N);
            ans--;
        }
        cout<<"Case #"<<ti<<": "<<ans<<endl;
    }
    return 0;
}
