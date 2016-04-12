#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<stack>
#include<list>
#include<vector>
#include<set>
#include<map>
#define FOR(i,bg,ed) for(int i=bg;i<=ed;++i)
#define RFOR(i,bg,ed) for(int i=bg;i>=ed;--i)
#define FOR_S(i,bg,ed,step) for(int i=bg;i<=ed;i+=step)
#define RFOR_S(i,bg,ed,step) for(int i=bg;i>=ed;i-=step)
#define MSET(a,i) memset(a,i,sizeof(a))
#define CIa1(a,i) cin>>a[i]
#define CIa2(a,i,j) cin>>a[i][j]
#define COa1(a,i) cout<<a[i]<<' '
#define COa2(a,i,j) cout<<a[i][j]<<' '
#define SCIa1(a,i) scanf("%d",&a[i])
#define SCIa2(a,i,j) scanf("%d",&a[i][j])
#define SCOa1(a,i) printf("%d ",a[i])
#define SCOa2(a,i,j) printf("%d ",a[i][j])
#define RFF(s) freopen(s,"r",stdin)
#define WFF(s) freopen(s,"w",stdout)
#define LL long long int
#define SPACE printf(" ")
#define ENTER printf("\n")
using namespace std;
const int MaxN = 26;
//int CT=0;
int FIND_ID=-1;

//���Ľڵ�
struct TrieNode
{
    bool isEnd; //�Ƿ���һ�����ʵĽ�β�ַ�
    int sonCount; //�ӽڵ�ĸ���
    TrieNode* son[MaxN];//�ӽڵ�ָ���б� ���ֻ��26��
    int id;//�Դ˽ڵ��ַ�Ϊ��β�ĵ��� ���ֵ䵥���б��е�λ��
    int sonList[30];

    TrieNode(){
        isEnd = false;
        sonCount = 0;
        id = -1;
        for (int i = 0; i < MaxN; ++i)
            son[i] = NULL;
    }
};

stack<TrieNode> *q[1000010] = {0};//����BFS�Ķ���

TrieNode* root;//���ڵ� ���������ֵ���

//����һ���� �����ʵ����� �ʵĳ��� �Լ� ���ڵ����б��е�λ��
void insert(char* word, int len, int id){
    TrieNode* curNode = root;//�Ը��ڵ�Ϊ���
    //cout<<root->sonCount<<endl;
    for (int i = 0; i < len; ++i)
    {
        //�ж�word[i]�Ƿ���curNode���ӽڵ��б���
        int index = word[i]-'a'; //index 0~25

        if(curNode->son[index]==NULL){//û�д��ַ�
            curNode->son[index] = new TrieNode();
            //��ӵ�list�� ���ٺ���ѭ���жϵĴ��� ����Ҫ�����ֵ������������ ��ʱ��û��
            curNode->sonList[curNode->sonCount++] = index;
        }

        if(i==len-1){//���ʵĽ�β
            curNode->son[index]->isEnd = true;
            curNode->son[index]->id = id;
        }

        curNode = curNode->son[index];
    }
}

bool cmp_int (const int& a, const int& b){
    return a < b;
}


//��ȡ������rootΪ���ģ���ɫ����㣬����ŵ�allElement��
vector<char> *getAll(Treenode *root, char *str, int i, vector<char*> &allElement)
{
    str[i] = root->ch;
    if(root->isColored)
    {
        str[i+1] = '\0';
        char *temp = (char*)malloc(strlen(str)*sizeof(char));
        strcpy(temp, str+1);
        temp[strlen(str)-1]='\0';
        allElement.push_back(temp);
    }
    for(int j=0;j<kind;j++)
    {
        if(root->next[j]!=NULL)
        {
           getAll(root->next[j],str,i+1, allElement);
        }
    }
}
//��ȡ������wordΪǰ׺�ĺ�ɫ��㣬����ŵ�allElement�У�������ǰ׺,ʹ��ʱ�������ӣ�
void autocomplete(Treenode *root, const char *word, char *str, int i, vector<char*> &allElement)
{
    Treenode *location=root;
    int j=0,branch=0;
    if(location==NULL) return ;
    while(word[j])
    {
        branch=word[j]-'a';
        if(!location->next[branch]) return ;
        location=location->next[branch];
        j++;
    }
    getAll(location, str, i, allElement);
}


//����ǰ׺��ѯ ��cnt������ �������ֵ��е�id
int find(char *word,int len)
{
    Treenode *location=root;
    int j=0
    while(word[j])
    {
        branch=word[j]-'a';
        if(location->next[branch])
            location=location->next[branch];
        j++;
    }
    return location->id;
}


int main(int argc, char const *argv[])
{
    RFF("1366.in");
    int N,M;
    cin>>N>>M;
    char s[1000+10];
    root = new TrieNode();//��ʼ�����ڵ�

    for (int i = 1; i <= N; ++i)
    {
        scanf("%s",s);
        insert(s,strlen(s),i);
    }

    char pre[1000+10];
    for (int i = 0; i < M; ++i)
    {
        int cnt = 0;
        scanf("%d %s",&cnt,pre);
        vector<char> *allElement;
        char str[1010];
        char tar[1010];
        allElement.push_back(pre);
        autocomplete(root,pre,str,0,allElement);
        allElement.sort();
        if (cnt>allElement.size())
            printf("-1\n");
        else
            tar=allElement[cnt-1];
        printf("%d\n",find(tar,strlen(tar)));
    }
    return 0;
}

/*
3 2
az
ay
b
2 a
3 a


4 2
ad
as
ase
asfg
2 as
1 ad

 */
