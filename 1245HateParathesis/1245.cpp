#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define OP 50000
using namespace std;
int op[1010];
int op_top = -1;
int res[1010];
int res_top = -1;
int temp[1010];
int temp_top = -1;
char line[1010];
void calc()
{
	int opr = temp[temp_top - 2];
	int x;
	switch(opr)
	{
		case '+' + OP:  x = temp[temp_top-1] + temp[temp_top];
						break;
		case '-' + OP:  x = temp[temp_top-1] - temp[temp_top];
						break;
		case '*' + OP:  x = temp[temp_top-1] * temp[temp_top];
						break;
		case '/' + OP:  x = temp[temp_top-1] / temp[temp_top];
						break;
	}
	temp_top -= 3;
	temp[++temp_top] = x;
}

bool check_top()
{
	if (temp_top < 1) return false;
	if (temp[temp_top] < OP && temp[temp_top - 1] < OP)
		return true;
	else return false;
}
void push_num(int &x, int &tens)
{
	//cout<<"num: "<<x<<endl;
	if (x)
	{
		res[++res_top] = x;
		x = 0;
	}
	tens = 1;
}
int main()
{
	gets(line);
	int tmp_num = 0;
	int tens = 1;
	for (int i = strlen(line) - 1; i >= 0; --i)
	{
		char tmp = line[i];
		//if (tmp == '\n') break;
		if (tmp == ' ')
		{
			push_num(tmp_num, tens);
			continue;
		}
		else if (tmp == '+' || tmp == '*' || tmp == '-' || tmp == '/' || tmp == '(' || tmp == ')')
		{
			push_num(tmp_num, tens);
			switch (tmp)
			{
				case ')': op[++op_top] = tmp + OP; break;
				case '(': while (op_top != -1 && op[op_top] != ')' + OP)
								res[++res_top] = op[op_top--];
						  if (op_top != -1 && op[op_top] == ')' + OP)
						  		--op_top;
						  break;
				case '+': while (1)
						  {
						  		if (op_top == -1 || op[op_top] == ')' + OP)
						  		{
						  			op[++op_top] = tmp + OP;
						  			break;
						  		}
								else
								{
									if (op[op_top] == '+' + OP || op[op_top] == '-' + OP)
									{	
										op[++op_top] = tmp + OP;
										break;
									}
									else
									{
										res[++res_top] = op[op_top--];
									}
								}

						  }
						  break;
						  
				case '-': while (1)
						  {
						  		if (op_top == -1 || op[op_top] == ')' + OP)
						  		{
						  			op[++op_top] = tmp + OP;
						  			break;
						  		}
								else
								{
									if (op[op_top] == '+' + OP || op[op_top] == '-' + OP)
									{	
										op[++op_top] = tmp + OP;
										break;
									}
									else
									{
										res[++res_top] = op[op_top--];
									}
								}

						  }
						  break;
				case '*': op[++op_top] = tmp + OP; break;
				case '/': op[++op_top] = tmp + OP; break;
			}
		}	
		else
		{
			tmp_num = tens * (tmp - '0') + tmp_num;
			tens *= 10;
		}
	}
	push_num(tmp_num, tens);
	while (op_top != -1)
		res[++res_top] = op[op_top--];

	for (int i = res_top; i >= 1; --i)
	{
		if (res[i] > OP)
			cout<<(char)(res[i] - OP)<<' ';
		else
			cout<<res[i]<<' ';
	}
	if (res[0] > OP)
		cout<<(char)(res[0] - OP)<<endl;
	else
		cout<<res[0]<<endl;

	//int nums = 0;
	while (res_top != -1)
	{
		while (check_top())
		{
			calc();
			// cout<<"stack: "<<endl;
			// for (int i = 0; i <= temp_top; ++i)
			// 	cout<<temp[i]<<' ';
			// cout<<endl;
		}
		temp[++temp_top] = res[res_top--];
	}
	while (check_top())
		calc();
	cout<<temp[0]<<endl;
	return 0;
}