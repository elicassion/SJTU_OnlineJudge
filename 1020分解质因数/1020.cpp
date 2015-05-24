#include<iostream>
#define ED 55000
using namespace std;
bool pp[55001]={0};
struct ans{
    int p;
    int ct;
};
ans ansT[10000];
int yct=1;
void prime()
{
	pp[2]=1;
	int h=2;
	for(;h<=ED;)
	{
		if(pp[h]){ h++;continue;}
		if(!pp[h])
		{
			int k=2*h;
			for(;k<=ED;)
			{
				pp[k]=0;
				k+=h;
			}
			h++;
	    }
	}
}
int main()
{
    for (int i=2;i<=55000;++i)
        pp[i]=1;
    for (int i=1;i<=9999;++i)
    {
        ansT[i].p=-1;
        ansT[i].ct=0;
    }
    int n;
    cin>>n;
    cout<<n<<'=';
    prime();
    for (int i=2;i<=ED;++i)
    {
        if (i>n) break;
        bool flag=0;
        while (pp[i] && n%i==0 && n!=1)
        {
            flag=1;
            ansT[yct].p=i;
            ansT[yct].ct++;
            n/=i;
        }
        if (flag)
            yct++;
    }
    if (n!=1)
    {
        ansT[yct].p=n;
        ansT[yct].ct=1;
        yct++;
    }
    for (int i=1;i<yct;++i)
        cout<<ansT[i].p<<'('<<ansT[i].ct<<')';
    cout<<endl;
    return 0;
}
