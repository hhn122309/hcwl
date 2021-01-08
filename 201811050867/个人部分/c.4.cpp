#include<iostream>
using namespace std;
void fun(int m,int n,char a[20][20],int k)
{
	int i,j,b[20][20];
while(k)
{
	for(i=0;i<n;i++)  //数组b作为一次感染的标志
		for(j=0;j<m;j++)
			if(a[i][j]=='X')
				b[i][j]=1;
			else
				b[i][j]=0;
	for(i=0;i<m;i++)//第一排处理
	{
		if(i==0)
		{
			if(b[0][i]==1)
			{
				if(a[0][i+1]!='P')//感染操作
					a[0][i+1]='X';
				if(a[1][i]!='P')
					a[1][i]='X';
			}
		}
		else if(i==m-1)
		{
			if(b[0][i]==1)
			{
				if(a[0][i-1]!='P')
					a[0][i-1]='X';
				if(a[1][i]!='P')
					a[1][i]='X';
			}
		}
		else
		{
			if(b[0][i]==1)
			{
				if(a[0][i-1]!='P')
					a[0][i-1]='X';
				if(a[0][i+1]!='P')
					a[0][i+1]='X';
				if(a[1][i]!='P')
					a[1][i]='X';
			}
		}

		}
	for(i=0;i<m;i++)//最后一排处理
	{
		if(i==0)
		{
			if(b[n-1][i]==1)
			{
				if(a[n-1][i+1]!='P')
					a[n-1][i+1]='X';
				if(a[n-2][i]!='P')
					a[n-2][i]='X';
			}
		}
		else if(i==m-1)
		{
			if(b[n-1][i]==1)
			{
				if(a[n-1][i-1]!='P')
					a[n-1][i-1]='X';
				if(a[n-2][i]!='P')
					a[n-2][i]='X';
			}
		}
		else
		{
			if(b[n-1][i]==1)
			{
				if(a[n-1][i-1]!='P')
					a[n-1][i-1]='X';
				if(a[n-1][i+1]!='P')
					a[n-1][i+1]='X';
				if(a[n-2][i]!='P')
					a[n-2][i]='X';
			}
		}

	}
	for(i=1;i<n-1;i++)//中间处理
		for(j=0;j<m;j++)
		{
			if(j==0)
			{
				if(b[i][j]==1)
				{
					if(a[i-1][j]!='P')
						a[i-1][j]='X';
					if(a[i+1][j]!='P')
						a[i+1][j]='X';
					if(a[i][j+1]!='P')
						a[i][j+1]='X';
				}
			}
			else if(j==m-1)
			{
				if(b[i][j]==1)
				{
					if(a[i-1][j]!='P')
						a[i-1][j]='X';
					if(a[i+1][j]!='P')
						a[i+1][j]='X';
					if(a[i][j-1]!='P')
						a[i][j-1]='X';
				}
			}
			else
			{
				if(b[i][j]==1)
				{	if(a[i-1][j]!='P')
						a[i-1][j]='X';
					if(a[i+1][j]!='P')
						a[i+1][j]='X';
					if(a[i][j+1]!='P')
						a[i][j+1]='X';
					if(a[i][j-1]!='P')
						a[i][j-1]='X';
				}
			}
		}
k--;
}
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
cout<<a[i][j];
cout<<endl;
}
}

int main()
{
int m,n,i,k;
char a[20][20];
cout<<"请输入m，n和地图"<<endl;
cin>>m>>n;
for(i=0;i<n;i++)
cin>>a[i];
cin>>k;
fun(m,n,a,k);
}