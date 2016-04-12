#include <iostream>
#include <cstdio>
using namespace std;
long long int T = 0;
int L[10010];
int N;
int M;
struct Que{
	int q[1000010];
	double ans;
	int h;
	int t;
	int num;
	Que():ans(0),h(0),t(0),num(0)
	{

	}
	void pop()
	{
		ans += T - q[h++];
	}
	void push(const int &x)
	{
		q[t++] = x;
		++num;
	}
	bool isEmpty()
	{
		return (h==t);
	}
	int top() const
	{
		return q[h];
	}
	int findlessthan(const long long int &x) const
	{
		int i = h;
		while (i != t && q[i] <= x)
			++i;
		return i-h;
	}

};
Que girl, boy;
int main()
{
	scanf("%d", &N);
	L[0] = 0;
	for (int i = 1; i <= N; ++i)
		scanf("%d", &L[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int gender, t;
		scanf("%d %d", &gender, &t);
		gender == 1 ? boy.push(t) : girl.push(t);
	}
	for (int i = 0; i < N; ++i)
	{
		T += L[i];
		int boy_av_num = boy.findlessthan(T);
		int girl_av_num = girl.findlessthan(T);
		int pop_num = min(boy_av_num, girl_av_num);
		//cout<<"pop_num: "<<pop_num<<endl;
		for (int j = 1; j <= pop_num; ++j)
		{
			boy.pop();
			girl.pop();
		}
	}
	printf("%.2f %.2f", boy.ans/boy.num, girl.ans/girl.num);
	return 0;
}
