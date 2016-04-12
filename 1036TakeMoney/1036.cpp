#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N;
struct Que{
	int h, t;
	int q[100010];
	long long int ans;
	long long int last;
	Que():h(0), t(0), ans(0), last(0)
	{
		memset(q,-1,sizeof(q));
	}
	void push(const int &x)
	{
		q[t++] = x;
	}
	int pop()
	{
		int tmp = q[h];
		++h;
		return tmp;
	}
	int head() const
	{
		return q[h];
	}
	bool isEmpty()
	{
		return (h == t);
	}
};
Que Q1, Q2, Q3, Q4;				//1,2,3 first 4 second

void calc_single_Q(Que & Q)
{
	long long int pre = 0;
	while (!Q.isEmpty())
	{
		Q.ans += pre;
		pre += Q.pop();
	}
	Q.last = pre;
}

int pop_cur(int cur[], long long int time_cur[])
{
	int min_num, min_cur = 0x7fffffff;
	for (int i = 0; i < 3; ++i)
	{
		if (cur[i] < min_cur)
		{
			min_num = i;
			min_cur = cur[i];
		}
	}
	cur[min_num] = -1;
	int time_tmp = time_cur[min_num];
	for (int i = 0; i < 3; ++i)
		time_cur[i] += min_cur;
	for (int i = 0; i < 3; ++i)
		if (i != min_num)
			cur[i] -= min_cur;
	return min_cur + time_tmp;

}

void push_cur(int cur[], Que & Q)
{
	int push_num = -1;
	for (int i = 0; i < 3; ++i)
	{
		if (cur[i] == -1)
		{
			push_num = i;
			break;
		}
	}
	cur[push_num] = Q.pop();
}

void calc_multi_Q(Que & Q)
{
	int cur[3] = {-1, -1, -1};
	long long int time_cur[3] = {0};
	if (N <= 2)
	{
		Q.last = max(Q.q[0], Q.q[1]);
		return;
	}
	for (int i = 0; i < 3; ++i)
	{
		cur[i] = Q.pop();
	}
	while (!Q.isEmpty())
	{
		Q.ans += pop_cur(cur, time_cur);
		push_cur(cur, Q);
	}
	long long int max_last = 0;
	for (int i = 0; i < 3; ++i)
	{
		long long int tmp_last = 0;
		if (cur[i] != -1)
			tmp_last = time_cur[i] + cur[i];
		else
			tmp_last = time_cur[i];
		if (tmp_last > max_last)
			max_last = tmp_last;
	}
	Q.last = max_last;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		Q4.push(tmp);
	}
	for (int i = 0; i < N; i += 3)
		Q1.push(Q4.q[i]);
	for (int i = 1; i < N; i += 3)
		Q2.push(Q4.q[i]);
	for (int i = 2; i < N; i += 3)
		Q3.push(Q4.q[i]);
	calc_single_Q(Q1);
	calc_single_Q(Q2);
	calc_single_Q(Q3);
	calc_multi_Q(Q4);
	cout<<Q1.ans + Q2.ans + Q3.ans<<' '<<max(max(Q1.last, Q2.last), Q3.last)<<endl;
	cout<<Q4.ans<<' '<<Q4.last<<endl;
	return 0;
}