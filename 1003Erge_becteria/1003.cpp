#include<iostream>
#include<cstdio>
using namespace std;
struct qT{
    int x;
    int y;
    int ct;
};
qT q[100010];
int t=1;
int h=1;
int mp[110][110]={0};
int n;
bool judge(int x,int y)
{
    if (x>=1 && x<=n && y>=1 && y<=n && mp[x][y]==0)
        return 1;
    else
        return 0;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
        {
            cin>>mp[i][j];
            if (mp[i][j]==1)
            {
                q[t].x=i;
                q[t].y=j;
                q[t].ct=0;
                t++;
            }
        }
    }
    while (h!=t)
    {
        if (judge(q[h].x+1,q[h].y))
        {
            q[t].x=q[h].x+1;
            q[t].y=q[h].y;
            mp[q[t].x][q[t].y]=1;
            q[t].ct=q[h].ct+1;
            t++;
        }
        if (judge(q[h].x-1,q[h].y))
        {
            q[t].x=q[h].x-1;
            q[t].y=q[h].y;
            mp[q[t].x][q[t].y]=1;
            q[t].ct=q[h].ct+1;
            t++;
        }
        if (judge(q[h].x,q[h].y+1))
        {
            q[t].x=q[h].x;
            q[t].y=q[h].y+1;
            mp[q[t].x][q[t].y]=1;
            q[t].ct=q[h].ct+1;
            t++;
        }
        if (judge(q[h].x,q[h].y-1))
        {
            q[t].x=q[h].x;
            q[t].y=q[h].y-1;
            mp[q[t].x][q[t].y]=1;
            q[t].ct=q[h].ct+1;
            t++;
        }
        h++;
    }
    cout<<q[t-1].ct<<endl;

}
