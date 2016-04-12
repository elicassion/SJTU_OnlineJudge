#include<iostream>
#include<cstdio>
using namespace std;
int fa[1000010];
int lson[1000010];
int rson[1000010];
int q[1000010];
int h=1,t=2;
int N;
bool jgTree()
{
    q[h] = 0;
    bool flag = true;
    while(h<t)
    {
        if (lson[q[h]] != -1 && flag)
            q[t++] = lson[q[h]];
        else if (lson[q[h]] == -1 && flag)
            flag = false;
        else if (lson[q[h]] != -1 && !flag)
            return false;
        if (rson[q[h]] != -1 && flag)
            q[t++] = rson[q[h]];
        else if (rson[q[h]] == -1 && flag)
            flag = false;
        else if (rson[q[h]] != -1 && !flag)
            return false;
        ++h;
    }
    return true;
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
    if (jgTree()) printf("true\n");
    else printf("false\n");
    return 0;
}
