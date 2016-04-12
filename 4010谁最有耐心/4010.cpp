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
const int MAXN=1000;
int N;
int a[MAXN+10];
bool v[MAXN+10]={0};
int curmin=0x7fffffff;
//int sa[MAXN+10];
int main()
{
    RFF("4010.in");
    cin>>N;
    FOR(i,0,N-1)
    {
        cin>>a[i];
        //sa[i]=a[i];
        if (a[i]<curmin)
            curmin=a[i];
    }
    //sort(sa+1,sa+1+N);
    FOR(i,0,N-1)
        a[i]-=curmin-1;
    int tN=N;
    int pt=0;
    bool FLAG=0;//0Лі1Дж
    while (tN!=1)
    {
        //int tpt=pt;
        if (!FLAG)
        {
            //bool first=0;
            for (;;++pt)
            {
                if (pt>N-1)
                    pt=0;
                /*if (pt==tpt)
                {
                    curmin+=first;
                    first=1;
                }*/
                --a[pt];
                if (a[pt]==0 && !v[pt])
                {
                    v[pt]=1;
                    //cout<<"out: "<<pt<<endl;
                    //cout<<"curmin: "<<curmin<<endl;
                    FLAG=1;
                    --pt;
                    --tN;
                    //++curmin;
                    break;
                }
            }
        }
        if (tN==1)
            break;
        //tpt=pt;
        //cout<<curmin<<endl;
        //cout<<pt<<endl;
        if (FLAG)
        {
            //bool first=0;
            for(;;--pt)
            {
                //cout<<pt<<endl;
                if (pt<0)
                    pt=N-1;
                /*if (pt==tpt)
                {
                    curmin+=first;
                    first=1;
                }*/
                --a[pt];
                if (a[pt]==0 && !v[pt])
                {
                    v[pt]=1;
                    //cout<<"out: "<<pt<<endl;
                    //cout<<"curmin: "<<curmin<<endl;
                    FLAG=0;
                    ++pt;
                    --tN;
                    //++curmin;
                    break;
                }
            }
        }

    }
    FOR(i,0,N-1)
    {
        if (!v[i])
        {
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}
