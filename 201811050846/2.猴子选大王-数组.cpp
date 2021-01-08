#include<stdio.h>
int main()
{
	int m,n,number,count=1;		//number记猴子剩余个数，count记当前报数
	int monkey[999];
	int t;						//t记数组下标
	int i;
	printf("请输入猴子个数 m 和报数 n ：");
	scanf("%d%d",&m,&n);
	number = m;
	for(i=0;i<m;i++)
		monkey[i]=i+1;
	t=0;
	while(number>1)
	{
		if(monkey[t]>0)
		{
			if(count!=n)
			{
				count++;
				t=(t+1)%m;		//t=(t+1)%m实现数组下标加1
			}
			else
			{
				monkey[t]=0;
				count=1;
				number--;
				t=(t+1)%m;
			}
		}
		else
		{
			t=(t+1)%m;
		}
	}
	for(i=0;i<m;i++)
	{
		if(monkey[i]>0)
			printf("猴子大王：%d\n",monkey[i]);
	}
	return 0;
}
