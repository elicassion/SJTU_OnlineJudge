#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string r="<red>";
string red="</red>";
string y="<yellow>";
string yed="</yellow>";
string b="<blue>";
string bed="</blue>";
int rct=0,yct=0,bct=0;
int flag[1010]={0};//1r 2y 3b
int h=0;
int judge(string s,int k,int l)
{
    string tmp1="";
    string tmp2="";
    string tmp3="";
    string tmp4="";
    string tmp5="";
    for (int i=k;i<k+5 && i<l;++i)
        tmp1+=s[i];
    for (int i=k;i<k+6 && i<l;++i)
        tmp2+=s[i];
    for (int i=k;i<k+7 && i<l;++i)
        tmp3+=s[i];
    for (int i=k;i<k+8 && i<l;++i)
        tmp4+=s[i];
    for (int i=k;i<k+9 && i<l;++i)
        tmp5+=s[i];
    /*cout<<tmp1<<endl;
    cout<<tmp2<<endl;
    cout<<tmp3<<endl;
    cout<<tmp4<<endl;
    cout<<tmp5<<endl;*/
    if (tmp1 == r)
    {
        flag[++h]=1;
        return 5;
    }
    if (tmp2 == red)
    {
        h--;
        return 6;
    }
    else if (tmp2 == b)
    {
        flag[++h]=3;
        return 6;
    }
    if (tmp3 == bed)
    {
        h--;
        return 7;
    }
    if (tmp4 == y)
    {
        flag[++h]=2;
        return 8;
    }
    if (tmp5 == yed)
    {
        h--;
        return 9;
    }
    return 0;
}
bool isletter(char c)
{
    return (c>='A' && c<='Z' || c>='a' && c<='z');
}
int main()
{
    //freopen("1347.in","r",stdin);
    string s;
    getline(cin,s);
    int l=s.length();
    int st1=s.find(r);
    int st2=s.find(y);
    int st3=s.find(b);
    //cout<<st1<<' '<<st2<<' '<<st3<<endl;
    for (int i=min(min(st1,st2),st3);i<l;++i)
    {
        int p=judge(s,i,l);
        i+=p;
        //cout<<"p: "<<p<<' ';
        //cout<<"flag["<<h<<"] :"<<flag[h]<<endl;
        if (flag[h]==1 && isletter(s[i]))
            rct++;
        else if (flag[h]==2 && isletter(s[i]))
            yct++;
        else if (flag[h]==3 && isletter(s[i]))
            bct++;
    }
    cout<<rct<<' '<<yct<<' '<<bct<<endl;
    return 0;
}
