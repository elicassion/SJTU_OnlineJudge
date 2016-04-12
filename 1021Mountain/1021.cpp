#include<iomanip>
#include<iostream>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int mt[160][160] = {0};
int x = 1;
int y = 1;
int ct = 1;
int N;
int dir = 0;
int main()
{
    cin>>N;
    for (int K = N * N;K > 0; --K)
    {
        //cout<<"x: "<<x<<"y: "<<y<<'\n';
        mt[x][y] = ct;
        ++ct;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        while (!(nx > 0 && nx <= N && ny > 0 && ny <= N && mt[nx][ny] == 0) && K > 1)
        {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx;
        y = ny;
        /*for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                cout<<setw(6)<<mt[i][j];
            }
            cout<<'\n';
        }
        cout<<"-----------------\n";*/
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout<<setw(6)<<mt[i][j];
        }
        cout<<'\n';
    }
    cout<<'\n';
    return 0;
}
