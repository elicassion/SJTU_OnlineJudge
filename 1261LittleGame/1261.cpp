#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int N;
bool isFull=1;
char a[10][10];
int ct_x_row[10]={0},ct_x_col[10]={0},ct_x_lcor,ct_x_rcor;
int ct_y_row[10]={0},ct_y_col[10]={0},ct_y_lcor,ct_y_rcor;
void init()
{
    for (int i=0;i<=9;++i)
    {
        ct_x_row[i]=0;
        ct_x_col[i]=0;
        ct_x_lcor=0;
        ct_x_rcor=0;
        ct_y_row[i]=0;
        ct_y_col[i]=0;
        ct_y_lcor=0;
        ct_y_rcor=0;
    }
    for (int i=1;i<=4;++i)
        cin>>a[i];
    for (int i=1;i<=4;++i)
    {
        for (int j=1;j<=4;++j)
        {
            //scanf("%c",&a[i][j]);
            if (a[i][j-1]=='X')
            {
                ++ct_x_row[i];
                ++ct_x_col[j];
                if (i+j==5)
                    ++ct_x_lcor;
                if (i==j)
                    ++ct_x_rcor;
            }
            if (a[i][j-1]=='O')
            {
                ++ct_y_row[i];
                ++ct_y_col[j];
                if (i+j==5)
                    ++ct_y_lcor;
                if (i==j)
                    ++ct_y_rcor;
            }
            if (a[i][j-1]=='T')
            {
                ++ct_x_row[i];
                ++ct_x_col[j];
                ++ct_y_row[i];
                ++ct_y_col[j];
                if (i+j==5)
                {
                    ++ct_x_lcor;
                    ++ct_y_lcor;
                }
                if (i==j)
                {
                    ++ct_x_rcor;
                    ++ct_y_rcor;
                }
            }
            if (a[i][j-1]=='.')
            {
                isFull=0;
            }
        }
        //getchar();
    }
}
void doit()
{
    bool XF=0,YF=0;
    if (ct_x_lcor==4||ct_x_rcor==4)
        XF=1;
    if (ct_y_lcor==4||ct_y_rcor==4)
        YF=1;
    for (int i=1;i<=4;++i)
    {
        if (ct_x_row[i]==4||ct_x_col[i]==4)
            XF=1;
        if (ct_y_row[i]==4||ct_y_col[i]==4)
            YF=1;
    }

    if (XF&&YF)
        cout<<"Draw\n";
    else if (XF && !YF)
        cout<<"X won\n";
    else if (!XF && YF)
        cout<<"O won\n";
    else if (!XF && !YF && isFull)
        cout<<"Draw\n";
    else if (!isFull)
        cout<<"Game has not completed\n"<<endl;
}
int main()
{
    cin>>N;
    //getchar();
    for (int i=1;i<=N;++i)
    {
        isFull=1;
        init();
        doit();
        //getchar();
    }
}
