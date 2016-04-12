#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
class BigInt{
    //流输入输出运算符
    friend ostream& operator << (ostream &out, const BigInt& x)
    {
        int x_size = x.s.size();
        if (x.s.back() && x_size>=1)
            out << x.s.back();
        else if (!x.s.back() && x_size ==1)
            out << x.s.back();
        for (int i=x_size-2;i>=0;--i)
        {
            char buf[40];
            sprintf(buf, "%08d", x.s[i]);
            for (int j=0;j<strlen(buf);++j) out << buf[j];
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

    friend BigInt max(const BigInt& x, const BigInt& y)
    {
        if (x>y)
            return x;
        else return y;
    }

    public:
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    //构造函数
    BigInt(long long int num = 0) { *this = num; }
    BigInt(const BigInt& b)
    {
        s.clear();
        int b_size=b.s.size();
        for (int i=0;i<b_size;++i)
            s.push_back(b.s[i]);
    }
    BigInt(const string& str) { *this = str; }

    //赋值运算符
    BigInt operator = (long long num)
    {
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while(num != 0);
        while (!s.back() && !s.empty())
            s.pop_back();
        if (s.empty())
            s.push_back(0);
        return *this;
    }
    BigInt operator = (const string& str)
    {
        s.clear();
        int x;
        int len = (str.length() - 1) / WIDTH + 1;
        for (int i=0;i<len;++i)
        {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        while (!s.back() && !s.empty())
            s.pop_back();
        if (s.empty())
            s.push_back(0);
        return *this;
    }

    //四则运算运算符
    BigInt operator + (const BigInt& b) const
    {
        BigInt c;
        c.s.clear();
        int this_size = s.size(), b_size = b.s.size();
        if (*this>=0 && b>=0)
        {
            for (int i=0, g=0; ; ++i)
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
        if (*this<0 && b<0)
        {
            BigInt c = this->abs() + b.abs();
            return c.minus();
        }
        if (*this<0 && b>=0)
        {
            return (b-this->abs());
        }
        if (*this>=0 && b<0)
        {
            return (*this-b.abs());
        }

    }
    BigInt operator += (const BigInt& b)
    {
        //cout<<"FUCK"<<b<<endl;
        *this=*this+b;
        return *this;
    }
    BigInt operator - (const BigInt& b) const
    {
        BigInt c;
        c.s.clear();
        int this_size = s.size(), b_size = b.s.size();
        if (*this == b) {c = 0; return c; }
        if (*this>=0 && b>=0)
        {
            if (*this > b)
            {
                //cout<<"ok"<<endl;
                //cout<<this_size<<' '<<b_size<<endl;
                for(int i = 0, g = 0; ; ++i)
                {
                    if (g == 0 && i >= this_size && i >= b_size) break;
                    int x = g;
                    if (i < this_size) x += s[i];
                    if (i < b_size) x -= b.s[i];
                    //cout<<x<<endl;
                    if (x < 0) {x += BASE; g = -1; }
                    else g=0;
                    c.s.push_back(x);

                    //system("pause");
                }
                while (!c.s.back())
                    c.s.pop_back();
                if (c.s.empty())
                    c.s.push_back(0);
                return c;
            }

            else
            {
                BigInt d = b-*this;
                return d.minus();
            }
        }
        if (*this>=0 && b<0)
        {
            return *this+b.abs();
        }
        if (*this<0 && b>=0)
        {
            BigInt d = this->abs() + b;
            return d.minus();
        }
        if (*this<0 && b<0)
        {
            return b.abs()-this->abs();
        }


    }

    BigInt operator -= (const BigInt& b)
    {
        *this = *this - b;
        return *this;
    }

    BigInt operator * (const BigInt& b) const
    {
        if (*this==0 || b==0)
            return 0;
        BigInt c;
        c.s.clear();
        c = 0;
        int this_size = s.size(), b_size = b.s.size();
        bool MINUS=(b<0)^(*this<0);
        BigInt p_b = b.abs();
        BigInt p_this = this->abs();
        for (int i=0;i<b_size;++i)
        {
            BigInt tmp;
            tmp.s.clear();
            BigInt sufzero=1;
            if (i != 0)
            {
                for (int j=1;j<=i;++j)
                    tmp.s.push_back(0);
            }
            long long int g = 0;
            for (int j = 0; ; ++j)
            {
                if (g == 0 && j >= this_size ) break;
                long long int x = g;
                if (j < this_size) x += (long long int)p_this.s[j] * p_b.s[i];
                tmp.s.push_back(x % BASE);
                g = x / BASE;
            }
            //cout<<tmp<<endl;
            c+=tmp;
            //cout<<c<<endl;
        }
        //cout<<c<<endl;
        if (!MINUS)
            return c;
        else return c.minus();
    }

    BigInt operator *= (const BigInt& b)
    {
        *this = *this * b;
        return *this;
    }



    //比较运算符
    bool operator < (const BigInt& b) const
    {
        if (this->s.back()>=0 && b.s.back()>=0)
        {
            if (s.size() != b.s.size()) return (s.size() < b.s.size() );
            for (int i=s.size()-1;i>=0;--i) if(s[i] != b.s[i]) return (s[i] < b.s[i]);
            return false;
        }
        else if (this->s.back()<0 && b.s.back()>=0)
            return true;
        else if (this->s.back()>=0 && b.s.back()<0)
            return false;
        else if (this->s.back()<0 && b.s.back()<0)
        {
            if (s.size() != b.s.size()) return (s.size() > b.s.size() );
            if (s.back() < b.s.back()) return true;
            for (int i=s.size()-2;i>=0;--i) if(s[i] != b.s[i]) return (s[i] > b.s[i]);
            return false;
        }

    }
    bool operator > (const BigInt& b) const { return b < *this; }
    bool operator <= (const BigInt& b) const { return !(b < *this); }
    bool operator >= (const BigInt& b) const { return !(*this < b); }
    bool operator != (const BigInt& b) const { return (*this < b) || (*this > b); }
    bool operator == (const BigInt& b) const { return !((*this < b) || (*this > b)); }
    bool operator ! () const { return *this==0; }


    //除二
    BigInt div_two() const
    {
        if (*this<2) return 0;
        int this_size=s.size();
        vector<int> tmp;
        tmp.push_back(0);
        int res=0;
        for (int i=this_size-1;i>=0;--i)
        {
            int ttmp=res*BASE+s[i];
            tmp.push_back(ttmp/2);
            res=ttmp%2;
            ++tmp[0];
        }
        int non_zero=1;
        while (!tmp[non_zero])
            ++non_zero;
        BigInt c;
        c.s.clear();
        for (int i=tmp[0];i>=non_zero;--i)
            c.s.push_back(tmp[i]);
        return c;
    }


    //高精度除以高精度(二分试商)
    BigInt operator / (const BigInt& b) const
    {
        assert(b!=0 && "divide 0");
        BigInt tmp_b = b.abs();
        BigInt tmp_this = this->abs();
        //cout<<tmp_this<<' '<<tmp_b<<endl;
        bool MINUS=(b<0)^(*this<0); //0 positive
        if (tmp_this<tmp_b) return 0;
        int this_size = tmp_this.s.size();
        int b_size = tmp_b.s.size();
        BigInt left=1;
        BigInt right = tmp_this;
        BigInt tmpsum = left+right;
        BigInt mid = tmpsum.div_two();
        //cout<<mid<<' '<<mid*tmp_b<<endl;
        while ( !(tmp_this >= mid*tmp_b && tmp_this < (tmp_b+mid*tmp_b)) )
        {
            if (mid*tmp_b < tmp_this) left=mid+1;
            else right=mid;
            tmpsum = left+right;
            mid = tmpsum.div_two();
            //cout<<mid<<endl;
            //system("pause");
        }
        if (!MINUS)
            return mid;
        else return mid.minus();
    }

    //取余
    BigInt operator % (const BigInt& b) const
    {
        BigInt c = *this-(*this/b)*b;
        return c;
    }


    /*operator double () const
    {
        bool MINUS = (b<0);
        BigInt a_b = this->abs();
        int a_b_size = a_b.s.size();
        double d_num = 0;
        for (int i=a_b_size-1; i>=0; --i)
        {
            d_num += a_b.s[i];
            if (i!=0)
                d_num *= BASE;
        }
        if (!MINUS) return d_num;
        else return -d_num;
    }*/

    BigInt abs () const
    {
        //cout<<"FUCK"<<endl;
        BigInt tmp=*this;
        if (*this>=0)
            return tmp;
        else
        {
            tmp.s.back()=-tmp.s.back();
            //cout<<tmp<<endl;
            return tmp;
        }
    }

    BigInt minus () const
    {
        BigInt tmp_this = *this;
        tmp_this.s.back()=-tmp_this.s.back();
        return tmp_this;
    }


};

int a, b, c, N;
BigInt r1 = 1, r2 = 0, r3 = 0;
BigInt tmpr1;
int main()
{
    cin>>a>>b>>c>>N;
    for (int i = 1;i <= N; ++i)
    {
        tmpr1 = r1 * a + r2 * b + r3 * c;
        r3 += r2;
        r2 = r1;
        r1 = tmpr1;
    }
    cout<<r1 + r2 + r3<<endl;
}
