#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

//全局变量
const int MaxN = 30000+5;
//int g[MaxN][MaxN]={0};
int** g;
//邻接表存储图 注意g[i] 表示i号按钮的情况 g[i][0]存储的是它的出边的个数 g[i][1~g[i][0]]存储的是这些边
int in[MaxN]={0};//in[i]存储的是这个点的入度
bool del[MaxN]={0};//del[i]表示是否已经被删除
//优先队列: 指定了比较方法为数值小的优先级高 从而实现字典序
priority_queue< int,vector<int>,greater<int> > q;//如果不指定greater<int>为比较函数的话 系统会自动调用<来进行比较
int n;//按钮个数
int ans[MaxN]={0};//记录存储结果


//初始化输入图
void init()
{
    scanf("%d",&n);
    g = new int*[n+5];
    for (int i = 1; i <= n; ++i)//对每个节点的边
    {
        int m = 0;
        scanf("%d",&m);//记录这个点的边的数目
        g[i] = new int[m+10];
        g[i][0] = m;
        for (int j = 1; j <= g[i][0]; ++j)
        {
            scanf("%d",&g[i][j]);
            in[g[i][j]]++;//第j个点的入度加一
        }
    }
}

//返回是否可以进行拓扑排序
bool TopologicalSort(){
    //先放入所有入度为0的点
    for (int i = 1; i <= n; ++i) if(in[i]==0)
        q.push(i);
    if(q.size()==0) //没有入度为0的点...
        return false;
    //拓扑排序的结果一定是n位 所以用for指定次数
    for (int i = 1; i <= n; ++i)
    {
        int cur = q.top();//堆的形象出来了
        q.pop();
        if(del[cur])
            return false;
        del[cur] = true;//删除这个点
        ans[i] = cur;
        //删除这个点的所有边
        for (int j = 1; j <= g[cur][0]; ++j)
        {
            int nxt = g[cur][j];
            if(del[nxt])
                return false;//如果它连接了一个已经被删除的点 说明有环存在
            in[nxt]--;//让它连接的那个点的入度减一
            if(in[nxt]==0)
                q.push(nxt);
        }
    }
    return true;
}

void destory(){
    for (int i = 0; i < n+5; ++i)
    {
        delete[] g[i];
    }
}
int main(int argc, char const *argv[])
{
    init();
    if(TopologicalSort()){
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }else
        printf("no solution\n");
    destory();
    return 0;
}

/*
AOV网:顶点活动网络
    把一个有向无环图(DAG)进行拓扑排序，得到的次序就说明了，在进行某一项活动时，它的前驱（必要）活动都已经完成。
拓扑排序:对DAG进行拓扑排序。
    得到一个线性序列使得如果DAG中存在u->v，则在u在v的前面。

在这个题中，AOV指的是，按下一个按钮时，要保证所有能够使这个按钮弹开的按钮都已经被按下。

拓扑排序的步骤很简单。。
1.循环找到一个入度为0的点，把它和它的出边都从中图中删除。

2.如果图里最后剩下点，说明存在回路。


PS:堆和优先队列..貌似是一个事情/.. 直观地,可以认为把队列作为横坐标 纵坐标为优先级.形成一个沙堆 每次从上向下拿东西

*/
