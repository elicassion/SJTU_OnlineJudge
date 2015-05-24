#include <iostream>
#include <cstdio>
using namespace std;

typedef struct{
	int num, fillS, incS;
}Trees;

Trees tree[300010];
int inQ[200010];
int pos[200010],ans[200010];
int N;

int x(int l, int r){
	return (l+r) | (l!=r);
}

void update(int l, int r){
	if (l == r){
		tree[x(l, r)].num = ((tree[x(l, r)].fillS==-1) ? tree[x(l, r)].num : tree[x(l, r)].fillS) + tree[x(l, r)].incS;
		tree[x(l, r)].fillS = -1;
		tree[x(l, r)].incS = 0;
		return;
	}
	
	int mid = (l + r) / 2;
	int f1 = tree[x(l, r)].fillS, i1 = tree[x(l, r)].incS;
	tree[x(l, r)].fillS = -1;
	tree[x(l, r)].incS = 0;
	if (f1 != -1){
		tree[x(l, mid)].fillS = tree[x(mid+1, r)].fillS = f1;
		tree[x(l, mid)].incS = tree[x(mid+1, r)].incS = i1;
	}
	else{
		tree[x(l, mid)].incS += i1;
		tree[x(mid+1, r)].incS+=i1;
	}
	return;
}


int get_loc(int l, int r, int q){
	update(l, r);
	if (l == r){
		return tree[x(l, r)].num;
	}
	
	int mid = (l + r) /2;
	if (q <= mid){
		return get_loc(l, mid, q);
	}
	else{
		return get_loc(mid+1, r, q);
	}
}


void fill_mod(int l, int r, int ql, int qr, int num){
	if (ql > qr){
		return;
	}
	if (l>qr || r<ql){
		return;
	}
	
	update(l, r);
	if (l>=ql && r<=qr){
		tree[x(l, r)].fillS = num;
		return;
	}
	else{
		int mid = (l+r) / 2;
		fill_mod(l, mid, ql, qr, num);
		fill_mod(mid+1, r, ql, qr, num);
		return;
	}
}


void inc_mod(int l, int r, int ql, int qr){
	if (ql > qr){
		return;
	}
	if (l>qr || r<ql){
		return;
	}
	
	update(l, r);
	if (l>=ql && r<=qr){
		tree[x(l, r)].incS++;
		return;
	}
	else{
		int mid = (l+r) / 2;
		inc_mod(l, mid, ql, qr);
		inc_mod(mid+1, r, ql, qr);
		return;
	}
}


int find_r(int loc){
	int l = 1, r = N + 1;
	while (l != r){
		int mid = (l+r) / 2;
		int cur = get_loc(1, N, mid);
		if (cur <= loc) {l = mid + 1;} else {r = mid;}
	}
	return l;
}


void decT(int i){
	for (; i <= N ; i += i&(-i)){
		pos[i]--;
	}
}

int findT(int x){
	int c = 0;
	for (int g = (1<<20); g > 0; g>>=1){
		int i = c + g;
		if (i<=N && pos[i] <= x){
			x -= pos[i];
			c = i;
		}
	}
	return c+1;
}


int main(){
	//freopen("data.txt","r",stdin);
	//freopen("ans.txt","w",stdout);
	
	scanf("%d",&N);
	
	for (int i = 1; i <= 2*N; ++i){
		tree[i].num = 0;
		tree[i].incS =  0;
		tree[i].fillS = -1;
	}
	
	for (int i = 1; i <= N; ++i){
		int a, c;
		scanf("%d %d", &a, &c);
		int loc = min(c, get_loc(1, N, a) );
		inQ[i] = loc;
		int fillRange = find_r(loc);
		fill_mod(1, N, fillRange, a, loc);
		inc_mod(1, N, a+1, N);
	}
	/*for (int i = 1; i <= N; ++i){
		printf("%d %d\n",inQ[i].a, inQ[i].loc);
	}*/
	
	for (int i = 1; i <= N; ++i){
		pos[i] = i & (-i);
	}
	for (int i = N; i >= 1; --i){
		int seq = findT(inQ[i]);
		decT(seq);
		ans[seq] = i;
	}
	
	for (int i = N; i > 1; --i){
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[1]);
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;	
}

