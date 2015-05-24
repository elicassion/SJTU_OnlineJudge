#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 100000;
class stars {
private:
	int *star;
	bool *isCon;
	int size;
	int constellation;
public:
	stars(const int &s=MAX) {
		size = s;
		star = new int[s+1];
		isCon = new bool[s+1];
		constellation = 0;
		for(int i=1; i<=size; ++i) {
			star[i] = -1;
			isCon[i] = false;
		}
	}
	~stars() {
		delete [] isCon;
		delete [] star;
	}
	void connect(int a, int b) {
		if(isCon[a] && isCon[b] && find(a) != find(b)) --constellation;
		if(!isCon[a] && !isCon[b]) ++constellation;
		isCon[a] = true, isCon[b] = true;
 
		a = find(a), b = find(b);
		if(a == b) return;
		if(star[a] < star[b]) {
			star[a] += star[b];
			star[b] = a;
		}
		else {
			star[b] += star[a];
			star[a] = b;
		}
	}
	
	bool ask(const int &a, const int &b) {
		return find(a) == find(b);
	}
	
	int howMany() {return constellation;}
	
private:
	int find(const int &x) {
		if(star[x] < 0) return x;
		return star[x] = find(star[x]);
	}
};
 
 
int main() {
	int n, m;
	cin >> n >> m;
	stars lty(n);
	char command[2];
	int x, y;
	for(int i=0; i<m; ++i) {
		scanf("%s", command);
		if(command[0] == 'a') {
			scanf("%d%d", &x, &y);
			lty.connect(x,y);
		}
		else if(command[0] == 'b') {
			printf("%d\n", lty.howMany());
		}
		else {
			scanf("%d%d", &x, &y);
			if(lty.ask(x,y)) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	//system("pause");
}
