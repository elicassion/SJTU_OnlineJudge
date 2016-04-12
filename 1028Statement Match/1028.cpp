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
string p[100010];
int b_CT=0;
int i_CT=0;
int e_CT=0;
int t_CT=0;
int CT3=0;
int CT4=0;
int main()
{
    //RFF("1206.in");
    int N;
    cin>>N;
    string sent;
    for (int i = 1;i <= N; ++i)
    {
        cin>>sent;
        if(sent=="begin" || sent=="end" || sent=="if" || sent=="then" || sent=="else"){
			p[i]=sent;
		}

    }
    /*cout<<N<<endl;
    FOR(i,1,N)
        cout<<p[i]<<endl;*/
    bool judge=1;
    for (int i=1; i<=N; ++i){
		if (p[i]=="begin") ++b_CT;
		if (p[i]=="end")	--b_CT;
		if (p[i]=="if") {
			if (p[i+1]=="then") ++t_CT;
				else judge = 0;
		}
		if (p[i]=="else"){
			if(p[i-1]!="begin") ++CT4;
			else judge=0;
		}
		if (p[i]=="then") ++CT3;
		if(b_CT<0) judge=0;
		if(t_CT<CT4) judge=0;
		if(t_CT<CT3) judge=0;
	}
	if(b_CT!=0) judge=0;
	if(t_CT!=CT3) judge=0;
	if(judge) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	return 0;
}
