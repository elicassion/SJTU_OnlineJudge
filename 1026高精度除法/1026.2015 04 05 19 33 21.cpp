#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int a[10001],b[10001],c[10001];   
void init(int a[]) 
{   
	string s; 
	cin>>s;                        //读入字符串s 
	a[0]=s.length();           //用a[0]计算字符串 s的位数 
	for(int i=1;i<=a[0];i++)
	a[i]=s[a[0]-i]-'0';          //将数串s转换为数组a，并倒序存储． 
}
void print(int a[])              //打印输出
{
	if (a[0]==0){cout<<0<<endl;return;}
	for(int i=a[0];i>0;i--) cout<<a[i];
	cout<<endl;
}
int compare (int a[],int b[])  
			//比较a和b的大小关系，若a>b则为1，a<b则为-1,a=b则为0 
{
	if(a[0]>b[0]) return 1;                    //a的位数大于b则a比b大 
	if(a[0]<b[0]) return -1;                   //a的位数小于b则a比b小 
	for(int i=a[0];i>0;i--)                           //从高位到低位比较 
	{
		if (a[i]>b[i]) return 1; 
		if (a[i]<b[i]) return -1;
	} 
	return 0;                                        //各位都相等则两数相等。 
} 

void chugao(int a[],int b[],int c[])
{
	int tmp[10001]={0}; 
	c[0]=a[0]-b[0]+1;
	for (int k=c[0];k>0;k--)
	{                              
		for (int i=1;i<=b[0];i++) 
			tmp[i+k-1]=b[i];
		tmp[0]=b[0]+k-1;
		while(compare(a,tmp)>=0)
		{
			c[k]++;
			for(int i=k;i<=tmp[0];i++) 
			{
				if(a[i]<tmp[i])
				{
					a[i+1]--;a[i]+=10;
					if (a[i+1]==0 && a[0]==i+1)
						a[0]--;
				}         //若不够减则向上借一位 
				a[i]-=tmp[i];
			} 
			while(a[0]>0&&a[a[0]]==0) a[0]--;               //修正a的位数 
		} 
		  //用减法来模拟
	}
	while(c[0]>0&&c[c[0]]==0)c[0]--;
}
int main()
{
  	//freopen("1026.in","r",stdin);
	memset(a,0,sizeof(a));
  	memset(b,0,sizeof(b));
  	memset(c,0,sizeof(c));
  	init(a);init(b);
  	if (b[0]==1 && b[1]==0)
  	{
	  cout<<0<<endl;
	  return 0;
  	}
  	if (compare(a,b)<0)
  	{
  		cout<<0<<endl;
  		return 0;
  	}
  	chugao(a,b,c);
  	print(c);
  	return 0;
}

