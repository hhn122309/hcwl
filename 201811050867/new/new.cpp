#include <stdio.h>  
#include <iostream>
#include"HHT.h"
using namespace std;	
//**********主函数*****************
int main(int argc, char **argv)
{
	int m,i,k;
	char q[20], p[20];
	Mysql user;
	k=user.numpass();
	while (!k)
	{
		k = user.numpass();
	}
	user.ConnectDatabase();
	user.UsePromptPage();
	while (1)
	{
		char a[150], b[150], c[9][150], d[4][150];	//操作语句词
		printf("   \n请输入数字1-6进行对数据库的操作：\n");
		cin >> m;
		if (m == 6)
			break;
		else
			switch (m)
			{
			case 1:
				user.ShowAll();
				break;
			case 2:
				cout << "请输入你要查询药物的关键字（药品编号、药品名称、生产厂家、生产日期、保质期、用途、价格、数量、经手人）和信息内容，格式如：生产日期 2018-15-14" << endl;
				cin >> a;
				cin >> b;
				user.QueryDatabase(a, b);
				break;
			case 3:
				cout << "请输入你要增添药物的信息，顺序为药品编号、药品名称、生产厂家、生产日期、保质期、用途、价格、数量、经手人" << endl;
				for (i = 0; i < 9; i++)
				{
					cin >> c[i];
				}
				user.InsertData(c);
				break;
			case 4:
				cout << "请输入你要那一个删除药品，如：药品编号 3，即可删除药品编号为3的药物信息" << endl;
				cin >> a;
				cin >> b;
				user.DeleteData(a,b);
				break;
			case 5:
				cout << "请输入你要修改的信息和对应药物，如：药品名称 QYQ 药品编号 2\n";
				cout << "即可修改药品编号为2的药品的药品名称为QYQ" << endl;
				for (i = 0; i < 4; i++)
				{
					cin >> d[i];
				};
				user.ModifyData(d);
			default:
				cout << "请输入1-6数字" << endl;
			}		
	}
	printf(" \n *****************   \n  感谢你的使用！！！\n          --代码制作者侯浩楠小组");
	user.FreeConnect();
	//system("paues");
}
