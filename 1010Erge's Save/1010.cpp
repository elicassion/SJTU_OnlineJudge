#include<iostream>
#include<cstdlib>
using namespace std;
const int PERMONTH = 300;
int rem = 0;
int save = 0;
int main()
{
    for (int i=1;i<=12;++i)
    {
        int budget;
        cin>>budget;
        int tmp = rem + PERMONTH - budget;
        if (tmp < 0)
        {
            cout<<"-"<<i<<endl;
            //system("pause");
            return 0;
        }
        else
        {
            save += tmp / 100 * 100;
            rem = tmp % 100;
        }
    }
    cout<<save+save/5+rem<<endl;
    return 0;
}
