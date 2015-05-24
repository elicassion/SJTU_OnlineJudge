#include<iostream>
using namespace std;
int n;
int x[800];
int y[800];
double k[800][800];
int cts[800][800]={0};
inline double sk(int a,int b)
{
    return (y[b]-y[a])*1.0/(x[b]-x[a]);
}
int main()
{
    cin>>n;
    int maxct=-0x7fffffff;
    for (int i=1;i<=n;++i)
    {
        cin>>x[i]>>y[i];
    }
    if (n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    else
    {
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=n;++j)
            {
                if (i!=j)
                {
                    k[i][j]=sk(i,j);
                    k[j][i]=k[i][j];
                }
            }
        }
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=n;++j)
            {
                if (cts[i][j]>0 || cts[j][i]>0)
                    continue;
                cts[i][j]=2;
                int mem[800];
                int mct=0;
                if (i!=j)
                {
                    double k0=k[i][j];
                    for (int p=1;p<=n;++p)
                    {
                        if (k[i][p]==k0 && p!=i && p!=j)
                        {
                            cts[i][j]++;
                            mem[++mct]=p;
                        }
                    }
                }
                for (int q=1;q<=mct;q++)
                {
                    cts[mem[q]][i]=cts[i][j];
                    cts[mem[q]][j]=cts[i][j];
                }
                if (cts[i][j]>maxct)
                    maxct=cts[i][j];
            }
        }
        cout<<maxct<<endl;
        return 0;
    }
}
