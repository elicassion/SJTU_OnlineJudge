#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#define MaxNode 100015
using namespace std;
int stk[MaxNode];
int top;
typedef struct POINT
{
    double x;
    double y;
}POINT;
POINT point[MaxNode];
void sw(POINT point[],int i,int j)
{
    POINT tmp;
    tmp=point[i];
    point[i]=point[j];
    point[j]=tmp;
}
double multi(POINT p1,POINT p2,POINT p0) //叉乘
{
    return ((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x));
}
double distence(POINT p1,POINT p2) //p1,p2的距离
{
    return sqrt((double)((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}
int cmp(const void *a,const void *b)
{
    POINT *c=(POINT *)a;
    POINT *d=(POINT *)b;
    double k=multi(*c,*d,point[0]);
    if(k<0) return 1;
    else if(k==0&&distence(*c,point[0])>=distence(*d,point[0])) return 1; //极角相同，比距离
    else return -1;
}
void grahamscan(int n)
{
    int i,u;
    u=0;
    for(i = 1;i<= n-1;i++) //找到最左下的点p0
        if((point[i].y < point[u].y)||(point[i].y==point[u].y&&point[i].x < point[u].x))
            u=i;
    sw(point,0,u);
    qsort(point+1,n-1,sizeof(point[0]),cmp); //按极角排序
    for(i = 0;i <= 2;i++) stk[i] = i; //p0,p1,p2入栈
    top=2;
    for(i = 3;i <= n-1;i++) //最终凸包的各顶点的编号依次存在stack[]中。
    {
        while(multi(point[i],point[stk[top]],point[stk[top-1]])>=0) //弹出非左转的点
        {
            if(top==0)
                break;
            top--;
        }
        top++;
        stk[top] = i;
    }
}
//求凸包两点最远距离
double maxd()
{
    double md=-0x7fffffff;
    double tmpd;
    for (int i=0;i<=top;++i)
    {
        for (int j=i+1;j<=top;++j)
        {
            tmpd=distence(point[stk[i]],point[stk[j]]);
            if (tmpd>md)
                md=tmpd;
        }
    }
    return md;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        scanf("%lf %lf",&(point[i].x),&(point[i].y));
    grahamscan(n);
    printf("%.4lf\n",maxd());
}
