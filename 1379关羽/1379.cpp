#include<iostream>
using namespace std;
int N;
int pres[3000]={0};
int sum=0;
long long int ANS=0;
int ct=0;
int main()
{
    cin>>N;
    for (int i=1;i<=N;++i)
    {
        int x;
        cin>>x;
        pres[i]=pres[i-1]+x;
        sum+=x;
    }
    for (int i=0;i<=N-2;++i)
    {
        for (int j=i+1;j<=N-1;++j)
        {
            if ((pres[j]-pres[i])==sum/2)
                ct++;
        }
    }
    //cout<<ct<<endl;
    ANS=ct*(ct-1)/2;
    cout<<ANS<<endl;
    return 0;
}
