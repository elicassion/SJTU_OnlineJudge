#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>
#define RFF(s) freopen(s,"r",stdin)
#define WFF(s) freopen(s,"w",stdout)
using namespace std;
string i_s;
string s="";
stack<long long int> num;
stack<char> opr;
bool isnum(char ch)
{
	return (ch>='0' && ch<='9');
}
bool isopr(char ch,int index)
{
	if (ch == '*' || ch == '/' || ch == '^' || ch == '+' )
		return true;
	if (ch =='-')
	{
		if (index == 0)
			return false;
		else if (s[index-1]==')' || isnum(s[index-1]) )
			return true;
		else return false;
	}
}

bool ispio(char opr1, char opr2)
{
	if (opr1 == '^')
	{
		if (opr2 == '$')
			return false;
		else return true;
	}
	else if (opr1 == '*' || opr1 == '/')
	{
		if (opr2 == '^' || opr2 == '*' || opr2 == '/' || opr2 == '$')
			return false;
		else return true;
	}
	else if (opr1 == '+' || opr1 == '-')
	{
		if (opr2 == '^' || opr2 == '*' || opr2 == '^' || opr2 == '+' || opr2 == '-' || opr2 == '$')
			return false;
		else return true;
	}
}
bool calc()
{
	if (opr.empty())
		return false;
	char op = opr.top();
		opr.pop();
	if (num.empty())
		return false;
	long long int x,y;
	x = num.top();
	num.pop();
	if (op == '$')
	{
		num.push(0-x);
		return true;
	}
	if (num.empty())
		return false;
	y = num.top();
	num.pop();
	
	//cout<<y<<' '<<op<<' '<<x<<endl;
	switch(op)
	{
		case '+' : {
			num.push(y+x);
			break;
		}
		case '-' : {
			num.push(y-x);
			break;
		}
		case '*' : {
			num.push(y*x);
			break;
		}
		case '/' : {
			if (x==0)
			{
				return false;
			}
			num.push(y/x);
			break;
		}
		case '^' : {
			num.push((long long int)pow((double)y,(double)x));
			break;
		}
	}
	return true;
}
int main()
{
    //RFF("1033.in");
    //WFF("1033.out");
    //cout<<pow(-5,3)<<endl;
	getline(cin,i_s);
	for (int i=0;i<i_s.length();++i)
	{
		if (i_s[i]!=' ')
			s+=i_s[i];
	}
	long long int t_num = 0;
	//bool MINUS=false;
	for (int i=0;i<s.length();++i)
	{
		//cout<<s[i]<<endl;
		if (s[i]==')')
		{
			if (opr.empty())
			{
				cout<<"Error"<<endl;
				return 0;
			}
			while (opr.top()!='(')
				if (calc()==false)
				{
					cout<<"Error"<<endl;
					return 0;
				}
			if (opr.empty())
			{
				cout<<"Error"<<endl;
				return 0;
			}
			if (opr.top()=='(')
				opr.pop();
		}
		else if (s[i]=='(') opr.push(s[i]);
		else if (s[i]=='-' && !isopr(s[i],i))
			opr.push('$');
		else if (isnum(s[i]))
		{
			do
			{
				t_num = t_num*10 + (s[i]-48);
				++i;
			}while(isnum(s[i]));
			//if (!MINUS)
				num.push(t_num);
			//else
				//num.push(0-t_num);
			t_num=0;
			//MINUS=false;
			--i;
		}
		else if (isopr(s[i],i))
		{
			while (!opr.empty() && !ispio(s[i],opr.top()))
				if (calc()==false)
				{
					cout<<"Error"<<endl;
					return 0;
				}
			opr.push(s[i]);
		}
	}
	for (;!opr.empty();)
	{
		if (calc()==false)
		{
			cout<<"Error"<<endl;
			return 0;
		}
	}
	cout<<num.top()<<endl;
    return 0;
}
