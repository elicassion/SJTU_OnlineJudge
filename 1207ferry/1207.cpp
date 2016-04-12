#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
using namespace std;
int T = 0;
int N;
struct Que{
	int q[20010];
	int h, t;
	long long int wt;
	int num;
	void pop()
	{
		wt += T - q[h];
		++h;
	}
	void push(const int &x)
	{
		q[t++] = x;
		++num;
	}
	int wait_num()
	{
		return t-h;
	}
	int head()
	{
		return q[h];
	}
	bool isEmpty()
	{
		return h == t;
	}
	Que()
	{
		memset(q, 0, sizeof(q));
		h = 0;
		t = 0;
		wt = 0;
		num = 0;
	}
};
Que bus, truck;
int main()
{
	int p, q;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d %d", &p, &q);
		p ? truck.push(q) : bus.push(q);
	}
	while (!truck.isEmpty() || !bus.isEmpty())
	{
		int up_num = 0;
		while (!bus.isEmpty() && bus.head() <= T && up_num < 4)
		{
			++up_num;
			bus.pop();
		}
		while (!truck.isEmpty() && truck.head() <= T && up_num < 5)
		{
			++up_num;
			truck.pop();
		}
		while (!bus.isEmpty() && bus.head() <= T && up_num < 9)
		{
			++up_num;
			bus.pop();
		}
		while (!truck.isEmpty() && truck.head() <= T && up_num < 10)
		{
			++up_num;
			truck.pop();
		}
		T += 10;
	}
	printf("%.3f %.3f\n", bus.wt * 1.0 / bus.num, truck.wt * 1.0 / truck.num);
	return 0;
}