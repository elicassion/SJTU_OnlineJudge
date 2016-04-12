#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<string>
#include<stdio.h>
using namespace std;
int ls[20000];
int rb[20000];
int N;
int root;
int lo[20000];
int vi[20000]={0};
int ct[20000]={0};
int q[20000]={0};
void preOrder (int cur)
{
    printf("%d ", cur);
    vi[cur] = 1;
    if (ls[cur] != 0 && vi[ls[cur]] == 0)
        preOrder(ls[cur]);
    if (rb[ls[cur]] != 0 && vi[rb[ls[cur]]] == 0)
        preOrder(ls[rb[cur]]);
    if (rb[cur] != 0 && vi[rb[cur]] == 0)
        preOrder(rb[cur]);
}

void postOrder (int cur)
{
    if (ls[cur] != 0 && vi[ls[cur]] == 0)
        postOrder(ls[cur]);
    if (rb[ls[cur]] != 0 && vi[rb[ls[cur]]] == 0)
        postOrder(ls[rb[cur]]);

    printf("%d ", cur);
    vi[cur] = 1;
    if (rb[cur] != 0 && vi[rb[cur]] == 0)
        postOrder(rb[cur]);
}

void levelOrder()
{
    int h=1,t=2;
    q[h] = root;
    vi[root] = 1;
    while(h<t)
    {
        //printf("h: %d\n", h);
        if (ls[q[h]] != 0)
            q[t++] = ls[q[h]];
        int cur = q[h];
        while (rb[cur] != 0)
        {
            if (!vi[rb[cur]])
            {
                //printf("cur:%d\n", cur);
                q[t++] = rb[cur];
                cur = rb[cur];
                vi[cur] = 1;
            }
            else
                break;
        }

        cur = ls[q[h]];
        while (rb[cur] != 0)
        {
            if (!vi[rb[cur]])
            {
                //printf("cur:%d\n", cur);
                q[t++] = rb[cur];
                cur = rb[cur];
                vi[cur] = 1;
            }
            else
                break;
        }

        //printf("t: %d\n", t);
        ++h;

    }
    for (int i=1;i<=N;++i)
        printf("%d ", q[i]);
}

int main()
{
    memset(ls, 0 ,sizeof(ls));
    memset(rb, 0 ,sizeof(rb));
    memset(lo, 0 ,sizeof(rb));
    int clo = 1;
    cin>>N;
    for(int i=1;i<=N;++i)
    {
        int cur;
        cin>>cur;
        cin>>ls[cur]>>rb[cur];
        ++ct[cur];
        ++ct[ls[cur]];
        ++ct[rb[cur]];
    }

    for (int i=1;i<=N;++i)
        if (ct[i] == 1)
            root = i;
    //printf("root: %d\n%d\n", root, rb[4]);
    preOrder(root);
    printf("\n");
    memset(vi, 0, sizeof(vi));
    postOrder(root);
    printf("\n");
    memset(vi, 0, sizeof(vi));
    levelOrder();
    printf("\n");
    return 0;
}
