#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int N, C;
int f[102] = {0};
int g[102] = {0};
int ct[102] = {0};
int main()
{
    scanf("%d %d", &N, &C);
    for (int i = 1; i <= N; ++i)
    {
        int cx;
        scanf("%d", &cx);
        ++ct[cx];
    }
    f[0] = 1;
    for (int i = 1; i <= 100; ++i)
        for (int j = 1; j <= 100; ++j)
        {
            if (j - i >= 0)
            {
                g[j]=g[j]+g[j-i]+(f[j]+f[j-i]);
                f[j]=f[j]+f[j-i];
            }
        }
    long long int res = 1;
    for (int i = 1; i <= C; ++i)
        res *= f[ct[i]];
    // for (int i = 1; i <= 100; ++i)
    //     cout<<f[i]<<' ';
    cout<<res<<endl;
    return 0;
}
