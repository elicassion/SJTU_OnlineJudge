#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int m[6][6]={0};
int p[7]={0};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
bool v[32]={false};


struct Point
{
    int x;
    int y;
    int id;
    Point(){
        x = y = id = 0 ;
    }
    Point(int a,int b){
        x = a;
        y = b;
        id = y + (x-1)*5;
    }
    Point(int pid){
        id = pid;
        y = id % 5;
        if(y==0 && id>0)
            y = 5;
        x = (id-1)/5 + 1 ;
    }

    bool isInPath()
    {
        for (int i = 0; i < 7; ++i)
            if(p[i]==id)
                return true;
            else if(p[i] > id)
                return false;
        return false;
    }
}q[50];

void init()
{
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            char c;
            cin>>c;
            if(c=='J')
                m[i][j]=1;
        }
    }
}


inline bool Check()
{
    memset(v,0,sizeof(v));
    int h = 0;
    int t = 0;
    Point start = p[0];
    q[t++] = start;
    int sum = m[start.x][start.y];
    int cur = 1;
    while(h < t)
    {
        Point& now = q[h];
        h++;
        v[now.id] = true;
        for (int i = 0; i < 4; ++i)
        {
            Point nx(now.x + dx[i],now.y + dy[i]);
            if(nx.x >5 || nx.x < 1 || nx.y > 5 || nx.y < 1)
                continue;
            if(!v[nx.id] && nx.isInPath())
            {
                v[nx.id]=1;
                cur++;
                sum+=m[nx.x][nx.y];
                if(7-cur+sum < 4)
                    return false;
                q[t++]=nx;
            }
        }
    }
    return (cur==7 && sum>=4);
}

int doit(){
    int ans = 0;
    for(p[0]=1; p[0]<=19; p[0]++)
        for(p[1]=p[0]+1; p[1]<=20; p[1]++)
            for(p[2]=p[1]+1; p[2]<=21; p[2]++)
                for(p[3]=p[2]+1; p[3]<=22; p[3]++)
                    for(p[4]=p[3]+1; p[4]<=23; p[4]++)
                        for(p[5]=p[4]+1; p[5]<=24; p[5]++)
                            for(p[6]=p[5]+1; p[6]<=25; p[6]++)
                                ans += Check();
    return ans;
}



int main()
{
    init();
    cout<<doit()<<endl;
    return 0;
}
