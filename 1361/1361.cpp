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
int N;
string stm[1010];
string legal[1010];
string component[1010][6];
int N_legal=0;
int ctcom[1010]={0};
int N_end=0;
void judgerep(string s)
{

        FOR(j,1,N_legal)
            if(s==legal[j])
                return;

        legal[++N_legal]=s;
        int lc=s.length();
        string tmp="";
        tmp=tmp+s[lc-3]+s[lc-2]+s[lc-1];
        //cout<<tmp<<endl;
        if (tmp=="end")
            ++N_end;

}
void doit(int i)
{
    if (component[i][1]=="Today")
        judgerep(component[i][3]);
    else if (component[i][1]=="Yesterday")
    {
        FOR(j,1,i-1)
            if (component[i][3]==component[j][ctcom[j]])
                judgerep(component[i][3]);
    }
    else if (component[i][1]=="Tomorrow")
    {
        FOR(j,i+1,N)
        {
            if (component[i][4]==component[j][ctcom[j]])
                judgerep(component[i][4]);
        }
    }
}
int main()
{
    //RFF("1361.in");
    //WFF("t.out");
    scanf("%d",&N);
    getchar();
    FOR(i,1,N)
    {
        getline(cin,stm[i]);
        component[i][4]="";
        int ctseg=0;
        int l=stm[i].length();
        string temp="";
        FOR(j,0,l-1)
        {
            if(stm[i][j]==' ' || stm[i][j]=='.')
            {
                component[i][++ctseg]=temp;
                temp="";
                continue;
            }
            temp+=stm[i][j];
        }
        ctcom[i]=ctseg;
        /*FOR(j,1,ctseg)
        {
            cout<<component[i][j]<<' ';
        }
        cout<<endl;*/
    }
    FOR(i,1,N)
        doit(i);
    cout<<N_legal<<' '<<N_end;
    return 0;
}
