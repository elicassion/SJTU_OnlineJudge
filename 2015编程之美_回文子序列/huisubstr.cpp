#include<string>
#include<cstring>
#include<iostream>
#define MOL 100007
using namespace std;
int f[1010][1010];
int t;
string s;
int main()
{
    cin>>t;
    for (int ti=1;ti<=t;++ti)
    {
        memset(f,0,sizeof(0));
        cin>>s;
        int sl=s.length();
        for (int i=0;i<sl;++i)
            f[i][i]=1;
        for (int i=2;i<=sl;++i)
        {
            for (int j=0;j<=sl-i;++j)
            {
                if (s[j]==s[i+j-1])
                    f[j][j+i-1]=f[j][j+i-2]+f[j+1][j+i-1]+1;
                else
                    f[j][j+i-1]=f[j][j+i-2]+f[j+1][j+i-1]-f[j+1][j+i-2];
                f[j][j+i-1]%=MOL;
            }
        }

        cout<<"Case #"<<ti<<": "<<f[0][sl-1]<<endl;
    }
    return 0;
}
