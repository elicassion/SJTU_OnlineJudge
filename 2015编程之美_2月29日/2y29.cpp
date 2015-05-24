#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int t;
string m1,m2;
int d1,ye1,d2,ye2;
bool ILY(int nYear)
{
    if ((nYear%400 == 0) || ((nYear%100 != 0) && (nYear%4 == 0)))
        return true;
    else
        return false;
}
bool cmp1(string m,int d)
{
    if(m=="January")
        return 0;
    else if (m=="February" && d<29)
        return 0;
    return 1;
}
bool cmp2(string m,int d)
{
    if(m=="January")
        return 0;
    else if (m=="February" && d<=29)
        return 0;
    return 1;
}

int fdr()
{
    int ly=0,ry=-1;
    if (ILY(ye1) && cmp2(m1,d1))
        ye1=ye1+1;
    if (ILY(ye2) && !cmp1(m2,d2))
        ye2=ye2-1;
    for (int i=ye1;i<=ye2;++i)
    {
        if (ILY(i))
        {
            ly=i;
            break;
        }
    }

    for (int i=ye2;i>=ye1;--i)
    {
        if (ILY(i))
        {
            ry=i;
            break;
        }
    }
    if (ly==ry)
        return 1;
    else if (ly>ry)
        return 0;

    int ct=0;
    int i=ly;
    while (i<ry)
    {
        if (i+400<=ry)
        {
            ct+=97;
            i+=400;
            continue;
        }
        else if (i+100<=ry)
        {
            if (ILY(i+100))
                ct+=25;
            else
                ct+=24;
            i+=100;
            continue;
        }
        else if (i+4<=ry)
        {
            if (ILY(i+4))
                ct++;
            i+=4;
            continue;
        }
    }
    if (ILY(ry))
        return ct+1;
    else
        return ct;
}
int main()
{
    //freopen("2y29.in","r",stdin);
    //freopen("2y29.out","w",stdout);
    cin>>t;
    for (int cas=1;cas<=t;++cas)
    {
        cin>>m1>>d1;
        getchar();
        cin>>ye1;
        cin>>m2>>d2;
        getchar();
        cin>>ye2;
        //cout<<m1<<' '<<d1<<' '<<ye1<<endl;
        //cout<<m2<<' '<<d2<<' '<<ye2<<endl;
        cout<<"Case #"<<cas<<": "<<fdr()<<endl;
    }
}
