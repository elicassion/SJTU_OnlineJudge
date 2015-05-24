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
#define FOR(i,bg,ed) for(int i=bg;i<=ed;++i)
#define RFOR(i,bg,ed) for(int i=bg;i>=ed;--i)
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
using namespace std;
int T;
int crw[10001]={0};//ctrowwords
int maxl[200]={0};
int row=0;
string words[10001];
int wordsl[10001]={0};
void init()
{
    MSET(crw,0);
    MSET(maxl,0);
    MSET(wordsl,0);
    FOR(i,1,10000)
        words[i]="";
    row=0;
    string s="";
    while (1)
    {
        getline(cin,s);
        if (s=="@")
            break;

        row++;
        int l=s.length();
        int i=0;
        while (i<=l-1)
        {
            while (s[i]==' ' && i+1<=l-1)
                i++;
            string tmpword="";
            int tmpwordl=0;
            while(s[i]!=' ' && i<=l-1)
            {
                tmpword+=s[i];
                i++;
                tmpwordl++;
            }
            if (tmpword!="")
            {
                crw[row]++;
                int wordl=tmpwordl+1;
                wordsl[row]+=wordl;
                words[row]+=tmpword+" ";
                if (wordl>maxl[crw[row]])
                    maxl[crw[row]]=wordl;
            }
        }

        //cout<<"FUCK"<<endl;
    }
}
void pt()
{
    FOR(i,1,row)
    {
        int l=wordsl[i];
        int lj=0;
        int ct=1;
        FOR(j,0,l-1)
        {
            printf("%c",words[i][j]);s
            if (words[i][j]==' ')
            {
                FOR(k,1,maxl[ct]-(j-lj+1))
                {
                    printf(" ");
                }
                lj=j+1;
                ct++;
            }
        }
        printf("\n");
    }
}
int main()
{
    //RFF("1305.in");
    //WFF("t.out");
    cin>>T;
    getchar();
    FOR(i,1,T)
    {
        init();
        pt();
    }
    return 0;
}
