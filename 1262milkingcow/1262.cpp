#include<stdio.h>
#include<string.h>
int n;
int myt=0;
int mnt=0;
int maxl=0;
int t[1000000];
void nongke()
{
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		l++;
		if(r>maxl) maxl=r;
		for(int j=l;j<=r;j++)
			t[j]++;
	}
}
void maxt()
{
	int i=0;
	while(t[i]==0) i++;
	int ct=0;
	int dt=0;
	for(;i<=maxl;i++)
	{
		if (t[i]==0)
        {
			if (ct>myt) myt=ct;
            ct=0;
            dt++;
        }
        else if (t[i]>0)
			{
				if (dt>mnt) mnt=dt;
				dt=0;
                ct++;
            }
		if (ct>myt) myt=ct;
		if (dt>mnt) mnt=dt;
    }
}
int main()
{
	//freopen("milk2.in","r",stdin);
	//freopen("milk2.out","w",stdout);
	scanf("%d",&n);
	memset(t,0,sizeof(t));
	nongke();
	maxt();
	printf("%d %d\n",myt,mnt);
	return 0;
}
