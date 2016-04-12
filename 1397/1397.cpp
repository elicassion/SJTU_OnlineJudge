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
public:
    string number_; //natrual
    bool sgn_;//sign 0 pos 1 neg
    static const int BASE=10;

    BigInt(long long int num)
    {
        sgn_ = num<=0;
        num = num>0?num:-num;
        if (num==0) number_="";
        else
        {
            while(num!=0)
            {
                number_+=(char)(num%10+'0');
                num/=10;
            }
            reverse(number_.begin(),number_.end());
        }
    }

	BigInt(string s="0"):number_(""),sgn_(0)
	{
	    //cout<<"S: "<<s<<endl;
	    if (s=="-") {sgn_=1; number_="1";}
	    else if (s[0]=='-') { sgn_=1; s.erase(0,1); }
	    else if (s[0]=='+') { sgn_=0; s.erase(0,1); }
	    s.erase(0,s.find_first_not_of('0'));
        int len=s.length();
        if (len==0) { number_="0"; sgn_=0; }
        else number_=s;
        //cout<<number_<<endl;
    }

	BigInt(const BigInt &b) { number_=b.number_; sgn_=b.sgn_; }
	~BigInt() { }


    static int abs_cmp(string a,string b)
    {
        int a_l=a.length();
        int b_l=b.length();
        if(a_l>b_l) return 1;
        else if(a_l<b_l)  return -1;
        else return a.compare(b);
    }

    // add sub mul div are abs calc funcs.
    string add(string a, string b) const
    {
        string res="";
        int a_l=a.length();
        int b_l=b.length();
        if(a_l<b_l) //complete zeros
            for(int i=1;i<=b_l-a_l;i++)
                a="0"+a;
        else
            for(int i=1;i<=a_l-b_l;i++)
                b="0"+b;
        a_l=a.length();
        int g=0;
        int x;
        for(int i=a_l-1;i>=0;i--)
        {
            x=a[i]-'0'+b[i]-'0'+g;
            g=x/10;
            res=char(x%10+'0')+res;
        }
        if(g!=0)
            res=char(g+'0')+res;
        return res;
    }

    string sub(string a, string b) const
    {
        string res;
        int del_l=a.length()-b.length();
        int g=0;
        for(int i=b.length()-1;i>=0;i--)
        {
            if(a[del_l+i]<b[i]+g)
            {
                res=char(a[del_l+i]-b[i]-g+'0'+10)+res;
                g=1;
            }
            else
            {
                res=char(a[del_l+i]-b[i]-g+'0')+res;
                g=0;
            }
        }
        for(int i=del_l-1;i>=0;i--)
        {
            if(a[i]-g>='0')
            {
                res=char(a[i]-g)+res;
                g=0;
            }
            else
            {
                res=char(a[i]-g+10)+res;
                g=1;
            }
        }
        res.erase(0,res.find_first_not_of('0'));
        return res;
    }

    string mul(string a, string b) const
    {
        int a_l=a.size(), b_l=b.size();
        int max_l = a_l + b_l;
        int *p = new int [max_l];
        for (int i=0; i<max_l; ++i) p[i]=0;
        //mul
        for (int i=0; i<b_l; ++i)
            for (int j=0; j<a_l; ++j)
                p[max_l-j-i-1] += (a[a_l-j-1]-'0') * (b[b_l-i-1]-'0');
        //carry
        for (int i=0;i<max_l-1;++i)
        {
            p[max_l-i-2] += p[max_l-i-1]/10;
            p[max_l-i-1] %= 10;
        }
        string res="";
        if (p[0]!=0)
            res+=p[0]+'0';
        for (int i=1; i<max_l; ++i)
            res+=p[i]+'0';
        delete [] p;
        return res;
    }


    string div(string a, string b) const
    {
        //remove more zeros
        a.erase(0,a.find_first_not_of('0'));
        b.erase(0,b.find_first_not_of('0'));
        int a_l=a.size();
        string res="", tmp="";
        int mark=0, ct=0;
        while (a.size()==b.size()&&a>=b || a.size()>b.size())
        {
            for (int i=tmp.size();i<tmp.size()+b.size()+1;++i)
            {
                tmp += a[i];
                ct += 1;
                if (tmp.size()==b.size()&&tmp>=b || tmp.size()>b.size())
                {
                    tmp = process_divide_positive(tmp,b,ct,&res);
                    a = tmp + a.substr(ct,a.size()-ct);
                    ct = tmp.size();
                    break;
                }
                else res += "0";
            }
        }
        int gap=a_l-res.size();
        for (int i=0;i<gap;++i) res += "0";
        return res.erase(0,res.find_first_not_of('0'));
    }

    string process_divide_positive(string tmp, string str2, int ct, string *p) const
    {
        int n=str2.size()+1;
        int* a= new int [n];
        int x;
        string b;
        bool FLAG=false;
        if (tmp.size()>str2.size()) FLAG=true;
        tmp = "0"+tmp;
        for (int i=1;b<=tmp;++i)
        {
            b="";
            if (FLAG) b+="0";
            for (int j=0;j<n;++j) a[j]=0;
            for (int j=0;j<n-1;++j)
            {
                a[n-1-j] = (str2[n-2-j]-'0') * i;
            }
            //carry
            for (int k=0;k<n-1;++k)
            {
                a[n-k-2] += a[n-k-1]/10;
                a[n-k-1] %= 10;
            }
            for (int j=0;j<n;++j)
            {
                b += (a[j]+'0');
            }
            x=i-1;
        }

        b="";
        if (FLAG) b+="0";
        for (int j=0;j<n;++j) a[j]=0;
        for (int j=0;j<n-1;++j)
        {
            a[n-1-j] = (str2[n-2-j]-'0') * x;
        }
        for (int k=0;k<n-1;++k)
        {
            a[n-k-2] += a[n-k-1]/10;
            a[n-k-1] %= 10;
        }
        for (int j=0;j<n;++j)
        {
            b += (a[j]+'0');
        }
        *p += (x+'0');

        int* m = new int [ct+1];
        for (int i=0;i<ct+1;++i)
        {
            m[i] = (tmp[i]-'0') - (b[i]-'0');
        }
        //carry
        for (int i=0;i<ct;++i)
        {
            if (m[ct-i]<0)
            {
                m[ct-i]+=10;
                m[ct-i-1]-=1;
            }
        }
        int num=0;
        string c="";
        for (int i=0;i<ct+1;++i)
        {
            if (m[i]==0) ++num;
            else break;
        }
        for (int i=num;i<ct+1;++i)
            c += (m[i]+'0');
        delete [] a;
        delete [] m;
        return c;
    }


	operator bool() { return !(number_=="0"); }

	operator double()
	{
	    double res=0;
	    int num_len = number_.length();
	    for (int i=0; i<num_len; ++i)
            res = res*BASE + (number_[i] - '0');
        if (sgn_) res=0.0-res;
        return res;
	}

	bool operator!=(const BigInt &b) const { return !((number_==b.number_) && (sgn_==b.sgn_)); }
	bool operator==(const BigInt &b) const { return !(*this!=b); }
	bool operator<(const BigInt &b) const
	{
	    if (sgn_ != b.sgn_) return !(sgn_ < b.sgn_);
	    else
        {
            if (!sgn_)
            {
                int a_l=number_.length();
                int b_l=b.number_.length();
                if (a_l!=b_l) return (a_l<b_l);
                else
                {
                    for (int i=0; i<a_l; ++i)
                        if (number_[i]!=b.number_[i])
                            return number_[i]<b.number_[i];
                    return false;
                }
            }
            else
            {
                int a_l=number_.length();
                int b_l=b.number_.length();
                if (a_l!=b_l) return !(a_l<b_l);
                else
                {
                    for (int i=0; i<a_l; ++i)
                        if (number_[i]!=b.number_[i])
                            return !(number_[i]<b.number_[i]);
                    return false;
                }
            }
        }
	}

	BigInt &operator=(const BigInt &b)
	{
	    sgn_=b.sgn_;
	    number_=b.number_;
	    return *this;
	}

    //+ - * / % judge sign and use abs calc funcs
	BigInt operator+(const BigInt &obj) const
	{
	    if(number_=="0" && obj.number_=="0") { return BigInt("0"); }
	    BigInt res;
	    string a="",b="";
        a=number_;
        b=obj.number_;
        if(sgn_ && obj.sgn_)
        {
            res.number_=add(a,b);
            res.sgn_=1;
        }
        else if(!sgn_ && !obj.sgn_)
        {
            res.number_=add(a,b);
            res.sgn_=0;
        }
        else if(sgn_ && !obj.sgn_)
        {
            if(abs_cmp(a,b)==1) { res.number_=sub(a,b); res.sgn_=1; }
            else if(abs_cmp(a,b)==0) { res.number_="0"; res.sgn_=0; }
            else if(abs_cmp(a,b)==-1) { res.number_=sub(b,a); }
        }
        else if(!sgn_ && obj.sgn_)
        {
            if(abs_cmp(a,b)==1) { res.number_=sub(a,b); }
            else if(abs_cmp(a,b)==0) { res.number_="0"; res.sgn_=0; }
            else if(abs_cmp(a,b)==-1) { res.number_=sub(b,a); res.sgn_=1; }
        }
        return res;
	}


	BigInt operator-(const BigInt &obj) const
	{
	    if(number_=="0" && obj.number_=="0") { return BigInt("0"); }
	    string a="",b="";
	    BigInt res;
        a=number_;
        b=obj.number_;
        if(!sgn_ && !obj.sgn_)
        {
            if(abs_cmp(a,b)==1) { res.number_=sub(a,b); }
            if(abs_cmp(a,b)==0) { res.number_="0"; res.sgn_=0; }
            if(abs_cmp(a,b)==-1) { res.number_=sub(b,a); res.sgn_=1; }
        }
        else if(sgn_ && obj.sgn_)
        {
            if(abs_cmp(a,b)==1) { res.number_=sub(a,b); res.sgn_=1; }
            if(abs_cmp(a,b)==0) { res.number_="0"; res.sgn_=0; }
            if(abs_cmp(a,b)==-1) { res.number_=sub(b,a); }

        }
        else if(!sgn_ && obj.sgn_)
        {
            res.number_=add(a,b);
        }
        else if(sgn_ && !obj.sgn_)
        {
            res.number_=add(a,b);
            res.sgn_=1;
        }
        return res;
	}

	BigInt operator*(const BigInt &obj) const
	{
	    if(number_=="0" || obj.number_=="0") { return BigInt("0"); }
	    string a="",b="";
	    BigInt res;
        a=number_;
        b=obj.number_;
        if( !((sgn_)^(obj.sgn_)) ) { res.number_ = mul(a,b); }
        else if( (sgn_)^(obj.sgn_) ) { res.number_ = mul(a,b); res.sgn_=1; }
        return res;
	}

	BigInt operator/(const BigInt &obj) const
	{
        assert(obj.number_!="0" && "divided by zero");
        if(number_=="0") { return BigInt("0"); }
        string a="",b="";
        BigInt res;
        a=number_;
        b=obj.number_;
        if( !((sgn_)^(obj.sgn_)) ) { res.number_=div(a,b); }
        else if( (sgn_)^(obj.sgn_) ) { res.number_=div(a,b); res.sgn_=1; }
        if (res.number_=="0" || res.number_=="") { res.number_="0"; res.sgn_=0; }
        return res;
    }

	BigInt operator%(const BigInt &obj) const
	{
	    assert(obj.number_!="0" && "divided by zero");
        if(number_=="0") { return BigInt("0"); }
        BigInt quo = *this / obj;
        BigInt res = *this - obj*quo;
        return res;
	}

	friend BigInt max(const BigInt &a, const BigInt &b)
	{
        BigInt res;
        if (!a.sgn_ && !b.sgn_) res = (abs_cmp(a.number_,b.number_)==1)?a:b;
        else if (!a.sgn_ && b.sgn_) res = a;
        else if (a.sgn_ && !b.sgn_) res = b;
        else if (a.sgn_ && b.sgn_) res = (abs_cmp(a.number_,b.number_)==-1)?a:b;
        return res;
	}

	friend BigInt min(const BigInt &a, const BigInt &b)
	{
	    BigInt res;
        if (!a.sgn_ && !b.sgn_) res = (abs_cmp(a.number_,b.number_)==-1)?a:b;
        else if (!a.sgn_ && b.sgn_) res = b;
        else if (a.sgn_ && !b.sgn_) res = a;
        else if (a.sgn_ && b.sgn_) res = (abs_cmp(a.number_,b.number_)==1)?a:b;
        return res;
	}

	void print() const
	{
	    if (sgn_) printf("-");
	    cout<<number_;
	}

    BigInt minus()
    {
        BigInt tmp=*this;
        if (tmp.number_!="0")
            tmp.sgn_=!tmp.sgn_;
        else tmp.sgn_=0;
        return tmp;
    }

    BigInt abs() const
    {
        BigInt tmp=*this;
        tmp.sgn_=0;
        return tmp;
    }

    static BigInt gcd(const BigInt &a, const BigInt &b)
    {
        const BigInt zero("0");
        BigInt big, small, tmp;
        BigInt absnum1_=a.abs();
        BigInt absnum2_=b.abs();
        big=max(absnum1_, absnum2_);
        small=min(absnum1_,absnum2_);
        tmp=big%small;
        while(tmp!=zero)
        {
            big=small;
            small=tmp;
            tmp=big%small;
        }
        return small;
    }

    static BigInt lcm(const BigInt &a, const BigInt &b)
    {
        BigInt gcd_num = BigInt::gcd(a,b);
        return (a*b/gcd_num).abs();
    }
};
int N;
int a[100010];
BigInt aa[100010];
BigInt ANS("0");
const BigInt mod("1000000007");
int main()
{
    //RFF("1397.in");
    //WFF("1397.out");
	cin>>N;
	for (int i=1; i<=N; ++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+N+1);
	for (int i=1;i<=N;++i)
	{
		aa[i]=a[i];
	}
	for (long long int i=1; i<=N; ++i)
	{
		ANS = ANS + (aa[N-i+1]-aa[i])*BigInt(N-i);
	}
	ANS=ANS%mod;
	ANS.print();
	//cout<<ANS<<endl;
    return 0;
}
