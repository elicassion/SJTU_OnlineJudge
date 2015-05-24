#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string text[200];
long textlen=0;

void dolist()
{
	//cout <<"DOING LIST"<<endl;
	string str;
	long n1,n2;
	cin >> n1 >> n2;
	getline(cin,str);
	if ( (n1<=0) || (n2>textlen) || (n1>n2) || str!="")
	{
		//cout <<"HEY!";
		cout << "Error!"<< endl;
		return;
	}
	
	for (long i=n1;i<=n2;i++)
	{
		cout << text[i]<< endl;
	}
}

void doins()
{
	long i,j;
	string str;
	cin >> i >> j;
	getchar();
	getline(cin,str);
	
	if ( (i<=0) || (i>textlen) || (j>text[i].length()+1) || (j<=0) ){
		cout << "Error!"<<endl;
		return;
	}
	
	if (j==text[i].length()+1)
		text[i] += str;
	else{
		string temp;
		for (long k=0;k<j-1;k++) temp+=text[i][k];
		for (long k=0;k<str.length();k++) temp+=str[k];
		for (long k=j-1;k<text[i].length();k++)temp+=text[i][k];		
		text[i]=temp;
		//text[i].insert(j-1,str);
	}
}

void dodel()
{
	long i,j,num;
	cin >> i >> j >> num;
	string str;
	getline(cin,str);
	if ( (i<=0) || (i>textlen) || ((j+num)>(text[i].length()+1)) || (j<=0) || (j>text[i].length()) || (num<=0) || (str!="") ){
		cout << "Error!"<<endl;
		return;
	}
	
	string temp;
	for (long k=0;k<j-1;k++) temp+=text[i][k];
	for (long k=j-1+num;k<text[i].length();k++)temp+=text[i][k];
	text[i]=temp;
	//text[i].erase(j-1,num);
}

bool doquit()
{
	string str;
	getline(cin,str);
	if ( (str!="") ){
		cout << "Error!"<<endl;
		return true;
	}
	for (long i=1;i<=textlen;i++)
	{
		cout << text[i]<<endl;
	}
	return false;
}


int main()
{
	freopen("1204.in","r",stdin);
	string command;
	do
	{
		textlen++;
		getline(cin,text[textlen]);
	}while(text[textlen]!="******");
	textlen--;
	//cout << "FILE READ SUCCESS!"<<endl;
	bool run=true;
	do
	{
		cin >> command;
		//cout << "COMMAND="<<command<<endl;
		if (command == "list") dolist(); 
		else if (command == "ins") doins(); 
		else if (command == "del") dodel(); 
		else if (command == "quit") run=doquit(); 
		else cout << "Error!" << endl;
		//default: cout << "ERROR!"<<endl;
	}while(run);
	return 0;
} 

