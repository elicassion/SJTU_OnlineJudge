#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstring>
using namespace std;
string week[8]={"","Monday.","Tuesday.","Wednesday.","Thursday.","Friday.","Saturday.","Sunday."};
struct ans
{
	int spid=-1;
	int obid=-1;
	int tyid=-1;
}; 
ans ansW[21];
int ansCt=0;
int main()
{
	//freopen("1256.in","r",stdin);
	//freopen("1256.out","w",stdout);
	
	int m,n,p;
	cin>>m>>n>>p;
	getchar();
	string name[11];
	for (int i=0;i<=m-1;++i)
		getline(cin,name[i]);
	//cout<<name[0]<<endl;
	//cout<<name[1]<<endl;
	//cout<<name[2]<<endl;
	
	int nonsense[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; //zhiyoufeihua
	int sumNon=0;
	for (int i=1;i<=p;++i)
	{
		int spid=-1,obid=-1,tyid=-1;
		string sent;
		getline(cin,sent);
		
		//cout<<sent<<endl;
		
		int mloc=sent.find(":");
		
		//cout<<mloc<<endl;
		
		string n1=sent.substr(0,mloc);
		
		//cout<<n1<<endl;
		
		for (int j=0;j<=m-1;++j)
		{
			if (n1==name[j])
			{	
				spid=j;
				break;
			}
		}
		string component[252]={""};
		int ct=0;
		string sentcut=sent.substr(mloc+2,sent.length()-mloc-1);
		
		//cout<<sentcut<<endl;
		
		while(sentcut.length())
		{
			int j;
			for (j=0;j<=sentcut.length()-1;++j)
			{
				if (sentcut[j]==' ')
				{
					component[ct+1]=sentcut.substr(0,j);
					string sentcuttmp=sentcut.substr(j+1,sentcut.length()-j-1);
					sentcut=sentcuttmp;					
					ct++;
					break;
				}
			}
			if (j==sentcut.length())
			{
				component[ct+1]=sentcut;
				ct++;
				break;
			}
			
		}
		
		//cout<<ct<<endl;
						
		for (int j=0;j<=m-1;++j)
		{
			if (component[1]==name[j])
			{
				obid=j;
				if (component[2]=="has" && component[3]=="the" && component[4]=="ring." && component[5]=="")
				{
					tyid=1;
					break;
				}
				else if (component[2]=="has" && component[4]=="the" && component[5]=="ring." && component[6]=="" && component[3]=="not")
				{
					tyid=2;
					break;
				}
			}
		}
		if (component[1]=="I" && component[2]!="has")
		{
			obid=spid;
			if (component[2]=="have" && component[3]=="the" && component[4]=="ring." && component[5]=="")
			{
				tyid=1;
			}
			else if (component[2]=="have" && component[4]=="the" && component[5]=="ring." && component[6]=="" && component[3]=="not")
			{
				tyid=2;
			}
		}
		if (component[1]=="Today" && component[2]=="is")
		{
			for (int j=1;j<=7;++j)
			{
				if (component[3]==week[j] && component[4]=="")
				{
					obid=j;
					tyid=3;
					break;
				}
			}
		}
		if (spid!=-1 && obid!=-1 && tyid!=-1)
		{
			ansCt++;
			ansW[ansCt].spid=spid;
			ansW[ansCt].obid=obid;
			ansW[ansCt].tyid=tyid;
			nonsense[spid]=0;
			//cout<<ansW[ansCt].spid<<ansW[ansCt].obid<<ansW[ansCt].tyid<<endl;
		}
		else
		{
			if (nonsense[spid] !=0 ) 
				nonsense[spid]=1;
			sumNon++; 
		}
	}
	
	int preNon=0;
	for (int i=0;i<m;++i)
	{
		if (nonsense[i] == 1 || nonsense[i] == -1)
			preNon++;
	}
	
	if (sumNon==p && m != 1)
	{
		cout<<"I am confused."<<endl;
		return 0;
	}
	else if (sumNon==p && m == 1)
	{
		cout<<name[0]<<endl;
		return 0;
	}
	
	int flag=0;
	int hasRing=-1;
	for (int i=0;i<m;++i)   //编号为 i 的人持有魔戒 
	{
		for (int k=1;k<=7;++k)
		{
		int folk=0;
		int right=0;
		int sp[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
		bool contro=1;
		for (int j=1;j<=ansCt;++j)
		{
			if (ansW[j].obid == i && ansW[j].tyid==1)
			{
				
				if (sp[ansW[j].spid] == -1)
				{
					sp[ansW[j].spid]=1;
					right++;
				}
				else if (sp[ansW[j].spid] == 1)
				{
					sp[ansW[j].spid]=1;
				}
				else
				{
					contro=0;
					break;
				}	
			}
			else if (ansW[j].obid == i && ansW[j].tyid==2)
			{
				if (sp[ansW[j].spid] == -1)
				{
					sp[ansW[j].spid]=0;
					folk++;
				}
				else if (sp[ansW[j].spid] == 0)
				{
					sp[ansW[j].spid]=0;
				}
				else
				{
					contro=0;
					break;
				}
			}
			else if (ansW[j].obid != i && ansW[j].tyid==1)
			{
				if (sp[ansW[j].spid] == -1)
				{
					sp[ansW[j].spid]=0;
					folk++;
				}
				else if (sp[ansW[j].spid] == 0)
				{
					sp[ansW[j].spid]=0;
				}
				else
				{
					contro=0;
					break;
				}
			}
			else if (ansW[j].obid != i && ansW[j].tyid == 2)
			{
				if (sp[ansW[j].spid] == -1)
				{
					sp[ansW[j].spid]=1;
					right++;
				}
				else if (sp[ansW[j].spid] == 1)
				{
					sp[ansW[j].spid]=1;
				}
				else
				{
					contro=0;
					break;
				}
			}
			else if (ansW[j].obid != k && ansW[j].tyid == 3)
			{
				if (sp[ansW[j].spid] == -1)
				{
					sp[ansW[j].spid]=0;
					folk++;
				}
				else if (sp[ansW[j].spid] == 0)
				{
					sp[ansW[j].spid]=0;
				}
				else
				{
					contro=0;
					break;
				}
			}
			else if (ansW[j].obid == k && ansW[j].tyid == 3)
			{
				if (sp[ansW[j].spid] == -1)
				{
					sp[ansW[j].spid]=1;
					right++;
				}
				else if (sp[ansW[j].spid] == 1)
				{
					sp[ansW[j].spid]=1;
				}
				else
				{
					contro=0;
					break;
				}
			}
		}
		if (!contro)
			continue;
		if (folk <= n && folk >= n-preNon && right <= m-n && right >= m-n-preNon)
		{
			flag++;
			hasRing=i;
			break;
		}
		}
	}
	
	if (flag == 1)
	{
		cout<<name[hasRing]<<endl;
		return 0;
	}
	else if (flag>1)
	{
		cout<<"I am confused."<<endl;
		return 0;
	}
	else if (flag == 0)
	{
		cout<<"It is impossible!"<<endl;
		return 0;
	}
}
