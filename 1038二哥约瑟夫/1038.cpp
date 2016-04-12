#include <iostream>
using namespace std;
int K[10000]={0};
int main()
{
    int M;
    cin>>M;
    int kick_id = 0;
    for (int i = 1; i <= M-1; ++i)
        cin>>K[i];
    for (int i = 2; i <= M; ++i)
        kick_id = (kick_id + K[M-i+1]) % i;
    cout<<kick_id + 1<<endl;
    return 0;
}