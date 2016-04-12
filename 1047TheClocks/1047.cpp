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
#define LOOP(x) for (s[x]=0; s[x]<4; ++s[x])
using namespace std;
int main()
{

	//RFF("clocks.in");
	//WFF("clocks.out");
	int a[9], b[9], ct, min_ct=0x7fffffff, res[10], s[10];
	for (int i=0; i<9; ++i)
    {
        scanf("%d", &a[i]);
        a[i]=a[i]/3%4;   // 0 1 2 3相当于12 3 6 9
    }
	LOOP(1) LOOP(2) LOOP(3)  //每个钟最多动4次 穷举
	LOOP(4)	LOOP(5)	LOOP(6)
	LOOP(7)	LOOP(8)	LOOP(9)
	{
		b[0] = (a[0]+s[1]+s[2]+s[4])%4; //动4次等于没动
		b[1] = (a[1]+s[1]+s[2]+s[3]+s[5])%4;
		b[2] = (a[2]+s[2]+s[3]+s[6])%4;
		b[3] = (a[3]+s[1]+s[4]+s[5]+s[7])%4;
		b[4] = (a[4]+s[1]+s[3]+s[5]+s[7]+s[9])%4;
		b[5] = (a[5]+s[3]+s[5]+s[6]+s[9])%4;
		b[6] = (a[6]+s[4]+s[7]+s[8])%4;
		b[7] = (a[7]+s[5]+s[7]+s[8]+s[9])%4;
		b[8] = (a[8]+s[6]+s[8]+s[9])%4;
		int sum=0;
		FOR(i,0,8)
            sum+=b[i];
		if (sum) continue; //没都到12点
		int t_ct=0;
		FOR(i,1,9)  //步数最小
            t_ct+=s[i];
		ct=t_ct;
		if (ct<min_ct)
		{
			min_ct=ct;
			FOR(i,1,9)
                res[i]=s[i];
		}
	}
	/*FOR(i,1,9)
        cout<<res[i]<<' ';
    ENTER;*/
	FOR(i,1,9)
		while (res[i]--)
			cout<<i<<' ';
    cout<<endl;
    return 0;
}
