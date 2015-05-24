#include <iostream>
#include <algorithm>
#define RFF(s) freopen(s,"r",stdin)
using namespace std;

long ans[110000],p[110000],l[110000],r[110000],first[110000]={};
long net[110000],tail[110000];
long n,ansl=0;

long check(long u, long father)
{
	long sum=1,t;
	bool issmall=true;
	for (long e=first[u]; e!=0; e=net[e])
    {
		if (tail[e]==father) continue;
		t = (check(tail[e],u));
		sum+=t;
		issmall = issmall && (t<=n/2);
	}
	issmall = issmall && (n-sum<=n/2);
	if (issmall){
		++ansl;
		ans[ansl]=u;
	}
	return sum;
}


int main()
{
	RFF("1358.in");
	long x,y;
	cin >> n;
	for (long i=1; i<n; ++i){
		cin >> x >> y;
		tail[i]=y;
		net[i]=first[x];
		first[x]=i;

		tail[2*n-i]=x;
		net[2*n-i]=first[y];
		first[y]=2*n-i;
	}
	cout<<"first\n";
	for (int i=1;i<=2*n-1;++i)
    {
        cout<<first[i]<<' ';
    }
    cout<<"\nnext\n";
    for (int i=1;i<=2*n-1;++i)
    {
        cout<<net[i]<<' ';
    }
    cout<<"\ntail\n";
    for (int i=1;i<=2*n-1;++i)
    {
        cout<<tail[i]<<' ';
    }
	/*check(1,0);
	sort(ans+1,ans+1+ansl);
	for (long i=1; i<=ansl; ++i){
		cout << ans[i] << endl;
	}*/
	return 0;
}
