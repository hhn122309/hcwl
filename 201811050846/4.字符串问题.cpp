#include<iostream>
using namespace std;
int main()
{
	int n, m;//定义行和列
	int b, c;
	c=0;
	cout<<"输入行列数"<<endl;
	cin >> n >> m;
	cout<<"输入周数"<<endl;
	cin>>b;
	//动态定义二维数组并进行赋值
	char** a = new char* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new char[n];
	}
	for ( i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
for(c=0;c<b;c++)
{
	i=0;
		for ( i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(a[i][j]=='X')
				{
					if(i+1<n && a[i+1][j]=='O')
					{
						a[i+1][j]='d';
					}
					if(j+1<m && a[i][j+1]=='O')
					{
						a[i][j+1]='d';
					}
					if(i-1>=0 && a[i-1][j]=='O')
					{
						a[i-1][j]='d';
					}
					if(j-1>=0 && a[i][j-1]=='O')
					{
						a[i][j-1]='d';
					}
				}
			}
		}
		for ( i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(a[i][j]=='d')
				a[i][j]='X';
		}
	}
	
}
	//输出二维数组
	cout<<"二维数组为"<<endl;
	for ( i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout <<  a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
