#include<iostream>
#include<cstdio>
using namespace std;
int fa[1000010];
int lson[1000010];
int rson[1000010];
int q[1000010];
int h=1,t=2;
int N;
void printTree()
{
    q[h] = 0;
    while(h<t)
    {
        if (lson[q[h]] != -1)
            q[t++] = lson[q[h]];
        if (rson[q[h]] != -1)
            q[t++] = rson[q[h]];
        ++h;
    }
    for (int i=1;i<=N;++i)
        printf("%d ", q[i]);
    printf("\n");
}
int main()
{
    scanf("%d", &N);
    for (int i=0;i<=N;++i)
    {
        fa[i] = -1;
        lson[i] = -1;
        rson[i] = -1;
    }
    fa[0] = 0;

    for (int i=1;i<N;++i)
    {
        int node;
        scanf("%d", &node);
        fa[i] = node;
        if (lson[node] == -1)
            lson[node] = i;
        else
            rson[node] = i;
    }
    printTree();
    return 0;
}
