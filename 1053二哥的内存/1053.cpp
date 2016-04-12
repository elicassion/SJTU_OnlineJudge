#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int N,M;
struct node{
    int x;
    int y;
    int num;
};
node p[10010];
vector<long long int> v;
int hshx[100010];// f of now to before
int hshy[100010];
bool cmpp(node x,node y)
{
    if (x.x<y.x)
        return true;
    else if (x.x==y.x)
    {
        if (x.y<y.y)
            return true;
        else return false;
    }
    else return false;
}
int main()
{
    //freopen("1053.in","r",stdin);
    //freopen("1053.out","w",stdout);
    scanf("%d",&N);
    for (int i=0;i<=100000;++i)
    {
        hshx[i]=i;
        hshy[i]=i;
    }
    for (int i=1;i<=N;++i)
    {
        int x,y,num;
        scanf("%d %d %d",&x,&y,&num);
        p[i].x=x;
        p[i].y=y;
        p[i].num=num;
        v.push_back(((long long int)x)*100000+y);
    }

    sort(v.begin(),v.end());
    sort(p+1,p+N+1,cmpp);
    int tmp[10010];
    for (int i=1;i<=N;++i)
    {
        tmp[i]=p[i].x;
    }
    vector<int> ox(tmp+1,tmp+N+1);
    for (int i=1;i<=N;++i)
    {
        tmp[i]=p[i].y;
    }
    vector<int> oy(tmp+1,tmp+N+1);
    for (int i=1;i<=N;++i)
    {
        tmp[i]=p[i].num;
    }
    vector<int> onum(tmp+1,tmp+N+1);
    /*cout<<"v:\n";
    for(int i=0;i<v.end()-v.begin();++i)
        cout<<v[i]<<' ';
    cout<<endl;
    cout<<"ox:\n";
    for(int i=0;i<ox.end()-ox.begin();++i)
        cout<<ox[i]<<' ';
    cout<<endl;
    cout<<"oy:\n";
    for(int i=0;i<oy.end()-oy.begin();++i)
        cout<<oy[i]<<' ';
    cout<<endl;
    cout<<"onum:\n";
    for(int i=0;i<onum.end()-onum.begin();++i)
        cout<<onum[i]<<' ';
    cout<<endl;
    cout<<"-------------------------------"<<endl;*/
    scanf("%d",&M);
    for (int i=1;i<=M;++i)
    {
        int opr,x,y;
        scanf("%d %d %d",&opr,&x,&y);
        if (opr==0)
        {
            int tmp;
            tmp=hshx[x];
            hshx[x]=hshx[y];
            hshx[y]=tmp;
        }
        if (opr==1)
        {
            int tmp;
            tmp=hshy[x];
            hshy[x]=hshy[y];
            hshy[y]=tmp;
        }
        /*if (opr==2)
            printf("FUCK\n");*/
        if (opr==2)
        {
            long long int marknum=((long long int)hshx[x])*100000+hshy[y];
            vector<int>::iterator xl,xu,yl;
            vector<long long int>::iterator vl,vu;
            vl = lower_bound(v.begin(),v.end(),marknum);
            vu = upper_bound(v.begin(),v.end(),marknum);

            //cout<<"hshx: "<<hshx[x]<<" hshy: "<<hshy[y]<<" marknum: "<<marknum<<" vl: "<<vl-v.begin()<<" vu: "<<vu-v.begin()<<endl;

            if (vl-v.begin()==vu-v.begin()-1)
            {
                xl = lower_bound(ox.begin(),ox.end(),hshx[x]);
                xu = upper_bound(ox.begin(),ox.end(),hshx[x]);
                yl = lower_bound(oy.begin()+(xl-ox.begin()),oy.begin()+(xu-ox.begin()),hshy[y]);
                //cout<<"xl: "<<xl-ox.begin()<<" xu: "<<xu-ox.begin()<<" yl: "<<yl-oy.begin()<<endl;
                printf("%d\n",onum[yl-oy.begin()]);
            }
            else
            {
                printf("0\n");
            }
        }
    }
}
