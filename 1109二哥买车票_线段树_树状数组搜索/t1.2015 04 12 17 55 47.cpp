#include <iostream>
#include <cstdio>
using namespace std;
int pos[100001];
int x(int l, int r){
	return (l+r) | (l!=r);
}
int main()
{
	/*int N;
	cin>>N;
	for (int i = 1; i <= N; ++i)
	{
		pos[i] = i & (-i);
		cout<<i<<": "<<pos[i]<<endl;
	}*/
	int l,r;
	for (;;)
	{	
		cin>>l>>r;
		cout<<x(l,r)<<endl;
	}
	//getchar();
	return 0;
	
} 

