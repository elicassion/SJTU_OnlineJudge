#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int a[10001],b[10001],c[10001];   
void init(int a[]) 
{   
	string s; 
	cin>>s;                        //�����ַ���s 
	a[0]=s.length();           //��a[0]�����ַ��� s��λ�� 
	for(int i=1;i<=a[0];i++)
	a[i]=s[a[0]-i]-'0';          //������sת��Ϊ����a��������洢�� 
}
void print(int a[])              //��ӡ���
{
	if (a[0]==0){cout<<0<<endl;return;}
	for(int i=a[0];i>0;i--) cout<<a[i];
	cout<<endl;
}
int compare (int a[],int b[])  
			//�Ƚ�a��b�Ĵ�С��ϵ����a>b��Ϊ1��a<b��Ϊ-1,a=b��Ϊ0 
{
	if(a[0]>b[0]) return 1;                    //a��λ������b��a��b�� 
	if(a[0]<b[0]) return -1;                   //a��λ��С��b��a��bС 
	for(int i=a[0];i>0;i--)                           //�Ӹ�λ����λ�Ƚ� 
	{
		if (a[i]>b[i]) return 1; 
		if (a[i]<b[i]) return -1;
	} 
	return 0;                                        //��λ�������������ȡ� 
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
				}         //�������������Ͻ�һλ 
				a[i]-=tmp[i];
			} 
			while(a[0]>0&&a[a[0]]==0) a[0]--;               //����a��λ�� 
		} 
		  //�ü�����ģ��
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

