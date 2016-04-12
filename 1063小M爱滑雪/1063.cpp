#include<stdio.h>
#include<string.h>
int ground[503][503];
int mem[503][503];
int r,c;
int da;
int dirx[5]={0,0,-1,0,1};
int diry[5]={0,-1,0,1,0};
int go(int x,int y)
{
	int xx,yy,he;he=0;
	if(mem[x][y]>0) return mem[x][y];
	for(int i=1;i<=4;i++)
	{
		xx=x+dirx[i];yy=y+diry[i];
		if(xx>=1&&xx<=r&&yy>=1&&yy<=c&&ground[xx][yy]<ground[x][y]){int wait=go(xx,yy);if(wait>he) he=wait;}
	}
	mem[x][y]=he+1;
	return mem[x][y];
}
int main()
{
	da=0;
	memset(ground,0,sizeof(mem));
	scanf("%d %d",&r,&c);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			scanf("%d",&ground[i][j]);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		{int length;length=go(i,j);if(length>da){da=length;}}
	printf("%d",da);
	return 0;
}
