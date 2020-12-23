#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=fun(a,b);
	printf("c=%d\n",c);
}
int fun(int a,int b)
{
	int m,n,i,j,c;
	m=a/10;
	n=a%10;
	i=b/10;
	j=b%10;
	c=n*1000+j*100+m*10+i;
	return c;
}
