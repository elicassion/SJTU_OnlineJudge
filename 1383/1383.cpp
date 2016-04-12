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
#include<queue>
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
long long int f[12][1<<11]; //״̬1Ϊ���̻����̵ڶ���״̬0Ϊ���̵�һ��
int W,H;
bool ok(int a)
{
    int x=1;
    int count=0;
    for (int i=0;i<H;i++,x<<=1)
    {
        if (a&x)//��λΪ1
            count++;
        else //��λΪ0
        {
            if (count&1)//����1�뵥��0��� ����
                return false;
            count=0;//1�ۼ�������
        }
    }
    return !(count&1);//���1������ �ò㲻������
}

void init()
{
    /*for (int i=1;i<=11;++i)
    {
        for (int j=0;j<(1<<H);++j)
            f[i][j]=0;
    }*/
    for (int i=0;i<(1<<H);++i)
        if (ok(i))
            f[1][i]=1;
    /*for (int i=0;i<(1<<H);++i)
        cout<<f[1][i]<<' ';
    ENTER;*/
    //f[0][(1<<H)-1]=1;
}


bool match(int j,int k)
{
    for (int i=1;i<(1<<H);)//���j,kÿһλ
    {
        if ((j&i)==0 && (k&i)==0) //���¶�Ϊ0
            return false;
        if ((j&i) && (k&i)) //���¶�Ϊ1 �������� ֻ�ܺ���
        {
            if ((j&(i<<1)) && (k&(i<<1)))//������ ����²�ǰһ����1  �ϲ�ǰһ����1 �˸��Ѻ���
            {
                i<<=2;
                continue;
            }
            else return false;//����������ɺ��� ͬʱ��ǰ�᲻������ ��false
        }
        i<<=1;
    }
    return true;//�������м�� ״̬��ת��
}
void doit()
{
    init();
    for (int i=2;i<=W;++i)
    {
        for (int j=0;j<(1<<H);++j)//��ǰ
        {
            for (int k=0;k<(1<<H);++k)//��һ��
            {
                if (match(j,k))
                    f[i][j]+=f[i-1][k];
            }
            //cout<<f[i][j]<<' ';
        }
        //ENTER;
    }
}
int main()
{
    while(cin>>W>>H)
    {
        if (W==0 && H==0)
            return 0;
        if ((W*H)%2==1)
        {
            cout<<0<<endl;
            continue;
        }
        if (W<H)
        {
            int t=W;
            W=H;
            H=t;
        }
        memset(f,0,sizeof(f));
        doit();
        cout<<f[W][(1<<H)-1]<<endl;
    }
    return 0;
}
