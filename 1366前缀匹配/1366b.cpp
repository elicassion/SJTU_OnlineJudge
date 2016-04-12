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

//树的节点
struct TrieNode
{
    bool isEnd; //是否是一个单词的结尾字符
    int sonCount; //子节点的个数
    TrieNode* son[MaxN];//子节点指针列表 最多只有26个
    int id;//以此节点字符为结尾的单词 在字典单词列表中的位置
    int sonList[30];

    TrieNode(){
        isEnd = false;
        sonCount = 0;
        id = -1;
        for (int i = 0; i < MaxN; ++i)
            son[i] = NULL;
    }
};

stack<TrieNode> *q[1000010] = {0};//用于BFS的队列

TrieNode* root;//根节点 代表整个字典树

//插入一个词 给出词的内容 词的长度 以及 词在单词列表中的位置
void insert(char* word, int len, int id){
    TrieNode* curNode = root;//以根节点为起点
    //cout<<root->sonCount<<endl;
    for (int i = 0; i < len; ++i)
    {
        //判断word[i]是否在curNode的子节点列表里
        int index = word[i]-'a'; //index 0~25

        if(curNode->son[index]==NULL){//没有此字符
            curNode->son[index] = new TrieNode();
            //添加到list中 减少后续循环判断的次数 但是要考虑字典序排序的问题 暂时还没做
            curNode->sonList[curNode->sonCount++] = index;
        }

        if(i==len-1){//单词的结尾
            curNode->son[index]->isEnd = true;
            curNode->son[index]->id = id;
        }

        curNode = curNode->son[index];
    }
}

bool cmp_int (const int& a, const int& b){
    return a < b;
}


//获取所有以root为根的（红色）结点，并存放到allElement中
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
//获取所有以word为前缀的红色结点，并存放到allElement中（不包含前缀,使用时需额外添加）
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


//根据前缀查询 第cnt个单词 返回在字典中的id
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
    root = new TrieNode();//初始化根节点

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
