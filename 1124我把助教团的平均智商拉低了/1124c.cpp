#include <iostream>

using namespace std;

long x[500],y[500],i[65100],prei[65100];


int main(){
	long ans=0,n,e0,i0;
	bool live;
	cin >> n;
	cin >> e0 >> i0;
	for (long j=1; j<=n; ++j){
		cin >> x[j] >> y[j];
	}
	for (long e=0; e<=65100; ++e){
			prei[e]=i[e]=-99999;
	}
	prei[e0]=i[e0]=i0;
//	for (long j=0;j<=n;++j){
//		i[e0][j]=i0;
//	}
	for (long j=1; j<=n; ++j){
		for (long e=0; e<=31000; ++e){

//			if (i[e,j-1]!=-99999) i[e][j] = i[e,j-1];
//			if (i[e-x[j],j-1]!=-99999) i[e][j] = max(i[e,j-1],i[e-x[j],j-1]+y[j]);
			if (e>=x[j] && prei[e-x[j]]!=-99999)
                i[e] = max(i[e],prei[e-x[j]]+y[j]);
		}
		for (long e=0; e<=31000; ++e){
			prei[e] = i[e];
		}
	}
	live = false;
//	cout << i[100][0]<< endl;
//	cout << i[50][1]<< endl;
//	cout << i[90][2]<< endl;
//	cout << i[30][3]<< endl;
	for (long e=31000; e>0; --e){
		if (i[e]> 70) {
			live = true;
//			cout << "I=" <<i[e][n] << endl;
//			cout <<"E="<< e << endl;
			if (i[e]*e > ans){

				ans = i[e]*e;
			}
		}
	}
	if (!live) cout << "Death" << endl;
	else cout << ans << endl;
	return 0;
}
