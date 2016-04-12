#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
string s;
int N;
bool v[100010]={0};
int f[100010]={0};
int maxn=0;
int ct_star=0;
bool BIGFLAG=0;
int ok(int idx,int put)
{
    bool FLAG1=0,FLAG2=0,FLAG3=0;
    if (s[idx+1]=='*')
    {
        FLAG1=1;
    }
    else
    {
        if (v[idx+1]+v[idx+2]+put==s[idx+1]-'0')
            FLAG1=1;
        else
            FLAG1=0;
    }
    if (s[idx]=='*')
    {
        FLAG2=1;
    }
    else
    {
        if (put+v[idx+1] <= s[idx]-'0')
            FLAG2=1;
        else
            FLAG2=0;
    }
    if (s[idx-1]=='*')
    {
        FLAG3=1;
    }
    else
    {
        if (put<=s[idx-1]-'0')
            FLAG3=1;
        else
            FLAG3=0;
    }
    if (FLAG1 && FLAG2 && FLAG3)
        return 1;
    else return 0;

}
void dfs(int idx,int cur)
{
    //cout<<"idx: "<<idx<<" cur: "<<cur<<endl;
    if (BIGFLAG)
        return;
    if (idx<1)
    {
        cout<<cur<<endl;
        for(int i=1;i<=N;++i)
        {
            cout<<v[i];
        }
        BIGFLAG=1;
        return;
    }
    for (int i=1;i>=0;--i)
    {
        if (ok(idx,i))
        {
            v[idx]=i;
            dfs(idx-1,cur+i);
            v[idx]=0;
        }
        else continue;
    }
}
int main()
{
    cin>>N;
    cin>>s;
    s="*"+s;
    s+="*";
    //cout<<s<<endl;
    int cur=0;
    dfs(N,cur);
    if (!BIGFLAG)
    {
        cout<<0<<endl;
        for (int i=1;i<=N;++i)
            cout<<0;
        system("pause");
        return 0;
    }
    system("pause");
    return 0;
}
