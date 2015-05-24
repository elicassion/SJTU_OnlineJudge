#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

//ȫ�ֱ���
const int MaxN = 30000+5;
//int g[MaxN][MaxN]={0};
int** g;
//�ڽӱ�洢ͼ ע��g[i] ��ʾi�Ű�ť����� g[i][0]�洢�������ĳ��ߵĸ��� g[i][1~g[i][0]]�洢������Щ��
int in[MaxN]={0};//in[i]�洢�������������
bool del[MaxN]={0};//del[i]��ʾ�Ƿ��Ѿ���ɾ��
//���ȶ���: ָ���˱ȽϷ���Ϊ��ֵС�����ȼ��� �Ӷ�ʵ���ֵ���
priority_queue< int,vector<int>,greater<int> > q;//�����ָ��greater<int>Ϊ�ȽϺ����Ļ� ϵͳ���Զ�����<�����бȽ�
int n;//��ť����
int ans[MaxN]={0};//��¼�洢���


//��ʼ������ͼ
void init()
{
    scanf("%d",&n);
    g = new int*[n+5];
    for (int i = 1; i <= n; ++i)//��ÿ���ڵ�ı�
    {
        int m = 0;
        scanf("%d",&m);//��¼�����ıߵ���Ŀ
        g[i] = new int[m+10];
        g[i][0] = m;
        for (int j = 1; j <= g[i][0]; ++j)
        {
            scanf("%d",&g[i][j]);
            in[g[i][j]]++;//��j�������ȼ�һ
        }
    }
}

//�����Ƿ���Խ�����������
bool TopologicalSort(){
    //�ȷ����������Ϊ0�ĵ�
    for (int i = 1; i <= n; ++i) if(in[i]==0)
        q.push(i);
    if(q.size()==0) //û�����Ϊ0�ĵ�...
        return false;
    //��������Ľ��һ����nλ ������forָ������
    for (int i = 1; i <= n; ++i)
    {
        int cur = q.top();//�ѵ����������
        q.pop();
        if(del[cur])
            return false;
        del[cur] = true;//ɾ�������
        ans[i] = cur;
        //ɾ�����������б�
        for (int j = 1; j <= g[cur][0]; ++j)
        {
            int nxt = g[cur][j];
            if(del[nxt])
                return false;//�����������һ���Ѿ���ɾ���ĵ� ˵���л�����
            in[nxt]--;//�������ӵ��Ǹ������ȼ�һ
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
AOV��:��������
    ��һ�������޻�ͼ(DAG)�����������򣬵õ��Ĵ����˵���ˣ��ڽ���ĳһ��ʱ������ǰ������Ҫ������Ѿ���ɡ�
��������:��DAG������������
    �õ�һ����������ʹ�����DAG�д���u->v������u��v��ǰ�档

��������У�AOVָ���ǣ�����һ����ťʱ��Ҫ��֤�����ܹ�ʹ�����ť�����İ�ť���Ѿ������¡�

��������Ĳ���ܼ򵥡���
1.ѭ���ҵ�һ�����Ϊ0�ĵ㣬���������ĳ��߶�����ͼ��ɾ����

2.���ͼ�����ʣ�µ㣬˵�����ڻ�·��


PS:�Ѻ����ȶ���..ò����һ������/.. ֱ�۵�,������Ϊ�Ѷ�����Ϊ������ ������Ϊ���ȼ�.�γ�һ��ɳ�� ÿ�δ��������ö���

*/
