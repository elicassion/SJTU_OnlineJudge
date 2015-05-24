#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;
string lines[10000];
vector<string> words[10000];
int col_len = 0;
int line_len = 0;
int col_longest[10000];
inline int getMax(int a,int b)
{
	return a > b ? a : b;
}

void split(string &str, vector<string> &ws)
{
	istringstream iss(str);
	do{
		string word;
		iss>>word;
		ws.push_back(word);
	}while(iss);
	ws.pop_back();
	col_len = getMax(col_len,ws.size());
}
void print_blank(int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<" ";
	}
	return;
}

int main()
{

	int N;
	cin>>N;
	for(int k = 0; k < N ; ++k)
    {
		col_len = 0 , line_len = 0;
		string input;
		memset(col_longest,0,sizeof(col_longest));
		memset(words,0,sizeof(col_longest));
		getline(cin,input);
		while(input!="@")
		{
			if(input!="")
				lines[line_len++] = input;
			getline(cin,input);
		}
		for (int i = 0; i < line_len; ++i)
			split(lines[i],words[i]);

		for (int i = 0; i < col_len; ++i)
		{
			int maxLen = 0;
			for (int j = 0; j < line_len; ++j) if( i < words[j].size() )
			{
				maxLen = getMax(maxLen,words[j][i].size());
			}
			col_longest[i] = maxLen;
		}
		for (int i = 0; i < line_len; ++i)
		{
			for (int j = 0; j < words[i].size(); ++j)
			{
				cout<<words[i][j]<<" ";
				print_blank(col_longest[j]-words[i][j].size());
			}
			cout<<endl;
		}
	}
	return 0;
}

