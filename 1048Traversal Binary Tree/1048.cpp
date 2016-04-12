#include<iostream>
#include<cstring>
#include<string.h>
#include<cstdio>
using namespace std;
int root;
int lson[2000]={0};
int rson[2000]={0};
bool be_son[2000]={0};
int N;
int q[2000];
void levelOrder()
{
    int h=1,t=2;
    q[h] = root;
    while (h<t)
    {
        //printf("h: %d", h);
        if (lson[q[h]] != 0)
            q[t++] = lson[q[h]];
        if (rson[q[h]] != 0)
            q[t++] = rson[q[h]];
        ++h;
    }
    for (int i=1;i<=N;++i)
        printf("%d\n", q[i]);
}
int main()
{
    scanf("%d", &N);
    int ct = 0;
    ct = N - ((N + 1) >> 1);
    //printf("\n%d\n", ct);
    for (int i=1;i<=ct;++i)
    {
        int cur;
        scanf("%d", &cur);
        scanf("%d %d", &lson[cur], &rson[cur]);
        be_son[lson[cur]] = 1;
        be_son[rson[cur]] = 1;
    }
    for (int i=1;i<=N;++i)
        if (!be_son[i])
            root = i;
    levelOrder();
}
