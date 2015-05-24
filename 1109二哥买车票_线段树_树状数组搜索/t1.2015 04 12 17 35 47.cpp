#include <iostream>
#include <cstdio>
using namespace std;
int pos[100001];
int main()
{
	/*int N;
	cin>>N;
	for (int i = 1; i <= N; ++i)
	{
		pos[i] = i & (-i);
		cout<<i<<": "<<pos[i]<<endl;
	}*/
	int l=8,r=4;
	cout<<((l+r) | (l!=r));
	//getchar();
	return 0;
	
} 

