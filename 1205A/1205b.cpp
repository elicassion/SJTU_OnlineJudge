#include<iostream>
using namespace std;
int M, N;
long long int v[4][10000]={0};
long long int A(int m, int n)
{
    long long int tmp;
    if (m == 0)
    {
        tmp = n + 1;
        v[m][n] = tmp;
        return tmp;
    }
    else if (m != 0 && n == 0)
    {
        if (v[m-1][1])
        {
            v[m][n] = v[m-1][1];
            return v[m-1][1];
        }
        else
        {
            tmp = A(m - 1, 1);
            v[m][n] = tmp;
            return tmp;
        }
    }
    else if (m != 0 && n != 0)
    {
        if (v[m][n-1] && v[m-1][v[m][n-1]])
        {
            v[m][n] = v[m-1][v[m][n-1]];
            return v[m-1][v[m][n-1]];
        }
        else
        {
            tmp = A(m - 1, A(m, n - 1));
            v[m][n] = tmp;
            return tmp;
        }

    }

}
int main()
{
    cin>>M>>N;
    cout<<A(M, N)<<endl;
    return 0;
}
