#include<iostream>
using namespace std;
int N;
int tree[100000];
int num[100000];
void printTree(int cur)
{
    if (cur > 1<<15)
        return;
    //cout<<"cur: "<<cur<<'\n';
    if (tree[cur << 1] != -1)
        printTree(cur << 1);
    if (tree[(cur << 1) + 1] != -1)
        printTree((cur << 1) + 1);
    if (tree[cur] != -1 && tree[cur] != 0)
        cout<<tree[cur]<<' ';
}
int main()
{
    cin>>N;
    for (int i = 0; i <= N*2; ++i)
    {
        tree[i] = -1;
        num[i] = -1;
    }
    tree[1] = 1;
    num[1] = 1;
    for (int i = 1;i <= N; ++i)
    {
        int self, l_son, r_son;
        cin >> self >> l_son >> r_son;
        int father = num[self];
        if (l_son != -1)
            num[l_son] = father << 1;
        if (r_son != -1)
            num[r_son] = (father << 1) + 1;
    }
    for (int i = 1; i <= N; ++i)
    {
        cout<<num[i]<<' ';
        tree[num[i]] = i;
    }

    cout<<'\n';
    printTree(1);
    cout<<'\n';
}
