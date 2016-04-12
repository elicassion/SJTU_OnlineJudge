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
class BigInt{
    //流输入输出运算符
    friend ostream& operator << (ostream &out, const BigInt& x)
    {
        int x_size = x.s.size();
        out << x.s.back();
        RFOR(i,x_size-2,0)
        {
            char buf[20];
            sprintf(buf, "%08d", x.s[i]);
            FOR(j,0,strlen(buf)-1) out << buf[j];
        }
        return out;
    }
    friend istream& operator >> (istream &in, BigInt& x)
    {
        string s;
        if (!(in >> s)) return in;
        x = s;
        return in;
    }


    public:
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    //构造函数
    BigInt(long long int num = 0) {*this = num;}

    //赋值运算符
    BigInt operator = (long long num)
    {
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    BigInt operator = (const string& str)
    {
        s.clear();
        int x;
        int len = (str.length() - 1) / WIDTH + 1;
        FOR(i,0,len-1)
        {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    //四则运算运算符
    BigInt operator + (const BigInt& b) const
    {
        BigInt c;
        c.s.clear();
        int this_size = s.size(), b_size = b.s.size();
        for (int i = 0, g = 0; ; ++i)
        {
            if (g == 0 && i >= this_size && i >= b_size) break;
            int x = g;
            if (i < this_size) x += s[i];
            if (i < b_size) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInt operator += (const BigInt& b)
    {
        *this=*this+b;
        return *this;
    }
    BigInt operator - (const BigInt& b) const
    {
        BigInt c;
        c.s.clear();
        int this_size = s.size(), b_size = b.s.size();
        if (*this == b) {c = 0; return c; }
        else if (*this > b)
        {
            for(int i = 0, g = 0; ; ++i)
            {
                if (g == 0 && i >= this_size && i >= b_size) break;
                int x = g;
                if (i < this_size) x += s[i];
                if (i < b_size) x -= b.s[i];
                if (x < 0) {x += BASE; g = -1; }
                c.s.push_back(x);
            }
            return c;
        }

        else
        {
            for(int i = 0, g = 0; ; ++i)
            {
                if (g == 0 && i >= this_size && i >= b_size) break;
                int x = g;
                if (i < b_size) x += b.s[i];
                if (i < this_size) x -= s[i];
                if (x < 0) {x += BASE; g = -1; }
                c.s.push_back(x);
            }
            c.s.back() = 0 - c.s.back();
            return c;
        }

    }

    BigInt operator -= (const BigInt& b)
    {
        *this = *this - b;
        return *this;
    }

    BigInt operator * (const BigInt& b) const
    {
        BigInt c;
        c.s.clear();
        c = 0;
        int this_size = s.size(), b_size = b.s.size();
        FOR(i,0,b_size-1)
        {
            BigInt tmp;
            tmp.s.clear();
            if (i != 0)
            {
                string sufzero = "";
                FOR(j,1,i)  sufzero += "00000000";
                tmp = sufzero;
            }
            long long int g = 0;
            for (int j = 0; ; ++j)
            {
                if (g == 0 && j >= this_size ) break;
                long long int x = g;
                if (j < this_size) x += (long long int)s[j] * b.s[i];
                tmp.s.push_back(x % BASE);
                g = x / BASE;

            }
            c += tmp;
        }
        return c;
    }

    BigInt operator *= (const BigInt& b)
    {
        *this = *this * b;
        return *this;
    }

    //比较运算符
    bool operator < (const BigInt& b) const
    {
        if (s.size() != b.s.size()) return (s.size() < b.s.size() );
        RFOR(i,s.size()-1,0) if(s[i] != b.s[i]) return (s[i] < b.s[i]);
        return false;
    }
    bool operator > (const BigInt& b) const { return b < *this; }
    bool operator <= (const BigInt& b) const { return !(b < *this); }
    bool operator >= (const BigInt& b) const { return !(*this < b); }
    bool operator != (const BigInt& b) const { return (*this < b) || (*this > b); }
    bool operator == (const BigInt& b) const { return !((*this < b) || (*this > b)); }

    //除数是低精度数除法
    BigInt divideSmall(int b)
    {
        BigInt tmp, ans;
        tmp.s.clear();
        ans.s.clear();
        int this_size = s.size();
        cout<<this_size<<endl;
        long long int r = 0;
        RFOR(i,this_size-1,0)
        {
            long long int x = r * BASE + s[i];

            tmp.s.push_back(x / b);
            r = x % b;
        }
        int tmp_size = tmp.s.size();
        int p = tmp_size - 1;
        cout<<p<<endl;
        while (tmp.s[p] == 0)
            p--;
        cout<<tmp.s[p]<<endl;
        cout<<tmp.s[p-1]<<endl;
        cout<<tmp.s[p-2]<<endl;
        if (p < 0) return 0;
        FOR(i,0,p)
            ans.s.push_back(tmp.s[i]);
        return ans;
    }

};
BigInt N;
BigInt P=1;
BigInt T;
int two=2;
BigInt Q;
int main()
{
    cin>>N;
    while (P<N)
    {
        P=P*2;
        cout<<P<<endl;
    }
    Q=P.divideSmall(two);
    T=N-Q;
    cout<<T<<endl;
    cout<<T*2+1<<endl;
    return 0;
}
