#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		string s;
		cin>>s;
		int ct=0;
		for (int j=0;j<s.length();++j)
		{
			if (s[j] =='(')
			{
				ct++;
			}
			else
				ct--;
			if (ct < 0)
			{
				cout<<"NO"<<endl;
				break;
			}
		}
		if (ct>0)
			cout<<"NO"<<endl;
		else if (ct == 0)
			cout<<"YES"<<endl;
	}
}
