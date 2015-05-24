#include<iostream>
using namespace std;
int f[20][20];
char mp[20][20];
int r,c;
int main()
{
    cin>>r>>c;
    for (int i=1;i<=r;++i)
    {
        for (int j=1;j<=r;++j)
        {
            cin>>mp[i][j];
        }
        //getchar();
    }
    while (x<=r && y<=c)
    {
        for (int i=2;i<=r;++i)
        {
            for (int j=2;j<=c;++j)
            {
                if (mp[i][j]!=mp[x][y])

            }
        }
    }
}
