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
#define MAX 100000000
using namespace std;
int a[16][16];
int N;
int ANS=MAX;
int f[65536][16]={0};
void doit()
{
	for(int i=0;i< 1<<(N-1);++i)
	//FOR(i,0,1<<(N-1)-1)
	{
		for (int j=1;j<N;++j)
		//FOR(j,1,N-1)
        {
			if(i == (1<<(j-1)))
				f[i][j]=a[0][j];
			else
			{
				if(i & (1<<(j-1)))
				{
					f[i][j]=MAX;
					for (int k=1;k<N;++k)
					//FOR(k,1,N-1)
						if(k!=j && (i & (1<<(k-1))) )
							f[i][j] = min(f[i^(1<<(j-1))][k]+a[k][j], f[i][j]);

				}
			}
		}
	}
	ANS=MAX;

	/*FOR(i,0,1<<(N-1)-1)
        FOR(j,1,N-1)
            cout<<f[i][j]<<endl;*/
    for (int i=1;i<N;++i)
	//FOR(i,1,N-1)
	{
		ANS=min(ANS,f[(1<<(N-1))-1][i]+a[i][0]);
		//cout<<ANS<<endl;
	}
}

int main()
{
    //RFF("1088.in");
    cin>>N;
    //cout<<N<<endl;
    if (N==1)
    {
        cout<<a[0][0]*2<<endl;
        return 0;
    }
    FOR(i,0,N-1)
    {
        FOR(j,0,N-1)
        {
            CIa2(a,i,j);
        }
    }
    doit();
    cout<<ANS<<endl;
    return 0;
}
