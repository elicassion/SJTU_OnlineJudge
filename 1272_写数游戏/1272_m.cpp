#include<iostream>
using namespace std;
int main(){
    freopen("1272.in","r",stdin);
	int n, num;
	bool write[101]={0}, judge=1;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>num;
		write[num]=1;
	}

	while(judge){
		judge=0;
		for(int j=1; j<100; ++j){
			if(write[j]){
				for(int i=j+1; i<=100; ++i){
					if(write[i]){
						if(!write[i/j]){
							write[i/j]=1;
							cout<<"i: "<<i<<" j: "<<j<<' '<<i/j<<endl;
							system("pause");
							judge=1;
						}
					}
				}
			}
		}
	}
	num=0;
	for(int i=0; i<=100; ++i){
		if(write[i]) ++num;
	}
	cout<<num<<endl;

	return 0;
}
