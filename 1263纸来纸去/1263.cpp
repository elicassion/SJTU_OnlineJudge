#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int n,m,field[60][60],dt[110][60][60]={0};
int main()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        cin>>field[i][j];

    for(int k=1;k<=n+m-2;k++)
    for(int x1=1;x1<=n;x1++)
    for(int x2=1;x2<=n;x2++)
    {
        if(x1==x2||x1-1>k||x2-1>k)
            continue;
        int y1=k-x1+2,y2=k-x2+2,max=0;
        if(y1>m||y2>m)
        continue;
        if(y1>1&&y2>1&&dt[k-1][x1][x2]>max)   max=dt[k-1][x1][x2];
        if(y1>1&&x2>1&&dt[k-1][x1][x2-1]>max)   max=dt[k-1][x1][x2-1];
        if(x1>1&&y2>1&&dt[k-1][x1-1][x2]>max)   max=dt[k-1][x1-1][x2];
        if(x1>1&&x2>1&&dt[k-1][x1-1][x2-1]>max)   max=dt[k-1][x1-1][x2-1];
        dt[k][x1][x2]=max+field[x1][y1]+field[x2][y2];
    }
    dt[n+m-2][n][n]=dt[n+m-3][n][n-1]>dt[n+m-3][n-1][n]?dt[n+m-3][n][n-1]:dt[n+m-3][n-1][n];
    cout<<dt[n+m-2][n][n]+field[1][1]+field[n][m]<<endl;
    return 0;
}
