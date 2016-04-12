#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
struct act
{
    int dh;
    int dw;
};

int f[400+5][32000+50]={0};
act acts[500+5];
int n;//һ���Ļ��Ŀ

void init(){
    cin>>n;
    for (int i = 0; i <= n; ++i)
    {
        cin>>acts[i].dh>>acts[i].dw;
    }//ע��acts[0]�洢���ǳ�ʼ���

}

void build(){
    memset(dp,-50000,sizeof(dp));

    dp[0][acts[0].dh] = acts[0].dw;//��ʼ��
    int curMax = 31000+50;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= curMax; ++j)
        {
            if(j >= acts[i].dh and dp[i-1][j-acts[i].dh] > -50000){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-acts[i].dh]+acts[i].dw);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int res = 0;
    for (int j = 1; j <= curMax; ++j)
    {
        if(dp[n][j] > 70){
            res = max(res,dp[n][j] * j);
        }
    }
    if(res)
        cout<<res<<endl;
    else
        cout<<"Death"<<endl;
}

int main(int argc, char const *argv[])
{
    init();
    build();
    return 0;
}

