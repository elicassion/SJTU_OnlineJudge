#include<iostream>
#include<cmath>
#define ED 5555000
using namespace std;
long long int n;
bool jp(long long int a)
{
	bool sexy=1;
	for(int i=2;i<=sqrt(a*1.0);i++)
	{
		if(a%i==0)
		{
			sexy=0;
			break;
		}
	}
	if(sexy) return 1;
	else return 0;
}

int main()
{
    cin>>n;
    if (n==0 || n==1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if (n%2==1)
    {
        long long int l=(n-1)/2;
        long long int r=n-l;
        while (l>=2)
        {
            if (jp(l) && jp(r))
            {
                cout<<l<<' '<<r<<endl;
                return 0;
            }
            l--;r++;
        }
        cout<<"NO"<<endl;
        return 0;
    }
    else
    {
        long long int hn=n/2;
        for (int i=1;i<=hn-2;++i)
        {
            if (jp(hn-i) && jp(hn+i))
            {
                cout<<hn-i<<' '<<hn+i<<endl;
                return 0;
            }
        }
        cout<<"NO"<<endl;
        return 0;
    }
}
