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
const int MAXNUM=712;
int cg[10]={6,2,5,5,4,5,6,3,7,6};
int ncg[8][8];
int N;
struct stick{
    int n;
    int num;
};
stick st[MAXNUM+10];
int c[90]={0};
int chtn(int x)
{
    int tmp=0;
    if (x==0)
        return 6;
    while(x!=0)
    {
        int k=x%10;
        tmp+=cg[k];
        x/=10;
    }
    return tmp;
}
bool cmp(stick x, stick y)
{
    if (x.n<y.n)
        return true;
    else return false;
}
int main()
{
    //WFF("1381.out");
    FOR(i,0,MAXNUM)
    {
        st[i].n=chtn(i);
        st[i].num=i;
        //cout<<st[i].n<<endl;
    }
    //cout<<"FUCK"<<endl;
    sort(st,st+MAXNUM+1,cmp);
    //cout<<"FUCK"<<endl;
    c[1]=0;c[24]=MAXNUM+1;
    for(int i=0;i<=MAXNUM;++i)
        if(c[st[i].n]==0)
            c[st[i].n]=i;
    for(int i=24;i>=1;--i)
        if(c[i]==0)
            c[i]=c[i+1];
    /*FOR(i,1,20)
        cout<<c[i]<<endl;*/
    //cout<<"FUCK"<<endl;
    cin>>N;
    if (N<7)
    {
        cout<<0<<endl;
        return 0;
    }
    int pA,pB;
    //cout<<N-2-1+1<<endl;
    pA=c[N-2-1+1]-1;
    //cout<<pA<<endl;
    int ANS=0;
    for (int i=pA;i>=0;--i)
    {

        int A=st[i].num;
        int nA=st[i].n;
        if (N-nA-2-1+1<2)
            continue;
        int pB=c[N-nA-2-1+1]-1;
        for (int j=pB;j>=0;--j)
        {
            int B=st[j].num;
            int nB=st[j].n;
            //cout<<A<<' '<<B<<endl;
            if (A>=B)
            {
                int C=A-B;
                int D=A+B;
                if (nA+nB+chtn(C)+1+2==N)
                {
                    ++ANS;
                    //cout<<A<<'-'<<B<<endl;
                    //cout<<nA<<' '<<nB<<' '<<chtn(C)<<endl;
                }

                /*if (nA+nB+chtn(D)+2+2==N)
                {
                    ++ANS;
                    //cout<<A<<'+'<<B<<endl;
                    //cout<<nA<<' '<<nB<<' '<<chtn(D)<<endl;
                }*/

            }
        }
    }
    cout<<ANS<<endl;
    return 0;
}
