#include <iostream>
#include <stdio.h>
using namespace std;
int dom[][13]={
				{0,31,28,31,30,31,30,31,31,30,31,30,31},
				{0,31,29,31,30,31,30,31,31,30,31,30,31}
			};
struct ymd
{
	int y,m,d;

	ymd(){}

	ymd(int yy,int mm,int dd)
	{
		y=yy;
		m=mm;
		d=dd;
	}

	ymd getNext()
	{
		ymd t(y,m,d);
		if(d < dom[leap()][m])
			t.d+=1;
		else if(m<12)
		{
			t.m+=1;
			t.d=1;
		}
		else
		{
			t.y+=1;
			t.m=1;
			t.d=1;
		}
		return t;
	}

	int leap()
	{
		return ((y % 4 == 0 && y % 100 != 0 )|| (y % 400 == 0?1:0));
	}

	int week()
	{
		int Y=y,M=m;
		if(m == 1 || m == 2)
		{
			Y--;
			M += 12;
		}
		int W = (d + M*2 + 3*(M+1)/5 + Y +Y/4 -Y/100 + Y/400) % 7;
		return W + 1;
	}



	bool deal_day()
	{
		if(week()==6||week()==7)
			return false;
		if(m==1&&d==1||m==5&&d>=1&&d<=3||m==10&&d>=1&&d<=7)
			return false;
		return true;
	}

	bool is_weekend()
	{
		return week()==6||week()==7;
	}

};

bool is_equal(ymd d1,ymd d2)
{
		return (d1.y==d2.y && d1.m==d2.m && d1.d==d2.d);
}

int ans_of_year(int year)
{
	bool isleap = (year%4==0 && year%100!=0 || year%400==0);
	int res = (isleap?366:365), t1, t2, t3=0, i;
	t1 = 104;
	if(isleap)
	{
		if(ymd(year,12,30).is_weekend())
			t1+=1;
		if(ymd(year,12,31).is_weekend())
			t1+=1;
	}
	else
	{
		if(ymd(year,12,31).is_weekend())
			t1+=1;
	}
	t2=11;
	if(ymd(year,1,1).is_weekend())
			t3+=1;
	for(i=1;i<4;i++)
		if(ymd(year,5,i).is_weekend())
			t3+=1;
	for(i=1;i<8;i++)
		if(ymd(year,10,i).is_weekend())
			t3+=1;
	res=res-t1-t2+t3;
	return res;
}

int main()
{
	int n,res=0,i;
	ymd d1,d2,t;
	scanf("%d",&n);
	while(n--)
	{
		res=0;
		scanf("%d-%d-%d %d-%d-%d",&d1.y,&d1.m,&d1.d,&d2.y,&d2.m,&d2.d);
		if(d2.y-d1.y<=1)
		{
			for(t=d1;!is_equal(t,d2.getNext());t=t.getNext())
				if(t.deal_day())
					res+=1;
		}
		else
		{
			for(t=d1;!is_equal(t,ymd(d1.y+1,1,1));t=t.getNext())
				if(t.deal_day())
					res+=1;
			for(t=ymd(d2.y,1,1);!is_equal(t,d2.getNext());t=t.getNext())
				if(t.deal_day())
					res+=1;
			for(i=d1.y+1;i<d2.y;i++)
				res+=ans_of_year(i);
		}
		printf("%d\n",res);
	}
	return 0;
}
