#include <stdio.h>  
#include <WinSock.h>   
#include "mysql.h"    
#include <Windows.h>
#include <iostream>
#include<stdlib.h>
#include "string.h"
#include"HHT.h"
#include <fstream>//ifstream读文件，ofstream写文件，fstream读写文件
#include <string>//文本对象，储存读取的内容
//********全局变量的定义*********
MYSQL mysql; //mysql连接
MYSQL_FIELD *fd;  //字段列数组
char field[32][32];  //存字段名二维数组
MYSQL_RES *res; //这个结构代表返回行的一个查询结果集
MYSQL_ROW column; //数据行的列
char query[150]; //查询语句

//**********函数声明**************
bool AllisNum(char[]);
//***********进入系统时的提示页面**
bool Mysql::UsePromptPage()
{
	printf("		***************************************\n");
	printf("		***************************************\n");
	printf("		**							 \n");
	printf("		**	欢迎使用药品信息管理系统         \n");
	printf("		**									 \n");
	printf("		***************************************\n");
	printf("		***************************************\n");
	printf("\n\n");
	printf("          请输入1,2,3,4,5,6数字，即可实现对应功能  \n\n");
	printf("             ***************************\n");
	printf("             ***************************\n");
	printf("             **  1：显示所有药物信息  **\n");
	printf("             **  2: 查询某个药物信息  **\n");
	printf("             **  3：增添某种药物      **\n");
	printf("             **  4：删除某种药物      **\n");
	printf("             **  5：修改某种药物信息  **\n");
	printf("             **  6：退出系统          **\n");
	printf("             ***************************\n");
	printf("             ***************************\n\n");
	return true;
}
//***********构造函数************
Mysql::Mysql(const char id[20],const char paw[20])
{
	strcpy(use_id, id);
	strcpy(use_paw, paw);
}
//**********连接数据库**********
void Mysql::ConnectDatabase()
{
	//初始化mysql  
	mysql_init(&mysql);  //连接mysql，数据库  
	const char host[] = "localhost";
	const char table[] = "medicine";
	const int port = 3306;
	//返回false则连接失败，返回true则连接成功  
	if (!(mysql_real_connect(&mysql, host, "root", "1223095464qq", table, port, NULL, 0)))
		//中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以
	{
		printf("连接失败,密码或用户名可能错误:%s\n", mysql_error(&mysql));
	}
	else
	{
		printf("连接数据库medicine成功...\n");
	}
}
//***********释放资源**************
void Mysql::FreeConnect()
{
	mysql_free_result(res);  //释放一个结果集合使用的内存。
	mysql_close(&mysql);	 //关闭一个服务器连接。
}
//***********显示表的所有信息******
bool Mysql::ShowAll()
{
	mysql_query(&mysql, "set names gbk");
	if (mysql_query(&mysql, "select * from yaopin"))        //执行SQL语句返回0 查询成功，返回1查询失败  
	{
		printf("查询失败 (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("查询成功\n");
	}
	res = mysql_store_result(&mysql);
	printf("一共有: %Id种药品\n", mysql_affected_rows(&mysql));		//打印数据行数 
	for (int i = 0; fd = mysql_fetch_field(res); i++)	 //获取字段名  
		strcpy(field[i], fd->name);
	int j = mysql_num_fields(res);	 // 获取列数  
	for (int i = 0; i < j; i++)		//打印字段  
		printf("%10s\t", field[i]);
	printf("\n");
	while (column = mysql_fetch_row(res))
	{
		for (int i = 0; i < j; i++)
			printf("%10s\t", column[i]);
		printf("\n");
	}
	return true;
}
//***********查询功能**************
bool Mysql::QueryDatabase(char a[], char b[])
{
	char c[150] = "\'%";
	strcpy(query, "select * from yaopin where ");
	strcat(query, a);
	strcat(query, " like ");
	strcat(c, b);
	strcat(c, "%\'");
	strcat(query, c);
	mysql_query(&mysql, "set names gbk");
	if (mysql_query(&mysql, query))        //执行SQL语句，返回0 查询成功，返回1查询失败    
	{
		printf("查询失败 (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("\n查询成功!!!\n");
	}
	res = mysql_store_result(&mysql);
	if (mysql_affected_rows(&mysql) == 0)
	{
		cout << "抱歉，没有该药物" << endl;
		return true;
	}
	printf("查询到一共有: %Id种药品\n", mysql_affected_rows(&mysql));		//打印数据行数
	for (int i = 0; fd = mysql_fetch_field(res); i++)  //获取字段名  
		strcpy(field[i], fd->name);
	int j = mysql_num_fields(res);  // 获取列数  
	for (int i = 0; i < j; i++)  //打印字段  
		printf("%10s\t", field[i]);
	printf("\n");
	while (column = mysql_fetch_row(res))
	{
		for (int i = 0; i < j; i++)
			printf("%10s\t", column[i]);
		printf("\n");
	}
	return true;
}
//***********增添数据  ************
bool Mysql::InsertData(char e[9][150])
{
	mysql_query(&mysql, "set names gbk");
	char d[150];
	for (int i = 1; i < 9; i++)
	{
		if (!AllisNum(e[i]) && strcmp(e[i], "null") != 0)		//给字符类型的数据添加‘’
		{
			strcpy(d, ",\'");
			strcat(d, e[i]);
			strcat(d, "\'");
			strcpy(e[i], d);
		}
		else
		{
			strcpy(d, ",");
			strcat(d, e[i]);
			strcpy(e[i], d);
		}
	}
	strcpy(query, "insert yaopin values(");
	strcat(query, e[0]);
	for (int i = 1; i < 9; i++)
	{
		strcat(query, e[i]);
	}
	strcat(query, ")");
	cout << query << endl;

	if (mysql_query(&mysql, query))        //执行SQL语句  
	{
		printf("增添失败 (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("增添成功\n");
		return true;
	}
}
//***********修改数据 *************
bool Mysql::ModifyData(char e[][150])
{
	char d[150] = "\'";
	mysql_query(&mysql, "set names gbk");
	strcat(d, e[3]);
	strcat(d, "\'");
	strcpy(e[3], d);
	strcpy(d, "\'");
	strcat(d, e[1]);
	strcat(d, "\'");
	strcpy(e[1], d);
	strcpy(query, "update yaopin set ");
	strcat(query, e[0]);
	strcat(query, "=");
	strcat(query, e[1]);
	strcat(query, " where ");
	strcat(query, e[2]);
	strcat(query, "=");
	strcat(query, e[3]);
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("修改失败 (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("修改成功\n");
		return true;
	}
}
//***********删除数据**************
bool Mysql::DeleteData(char a[150], char b[150])
{
	char d[150] = "\'";
	mysql_query(&mysql, "set names gbk");
	strcat(d, b);
	strcat(d, "\'");
	strcpy(query, "delete from yaopin where ");
	strcat(query, a);
	strcat(query, "=");
	strcat(query, d);
	if (mysql_query(&mysql, query))        //执行SQL语句  
	{
		printf("删除失败 (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("删除成功\n");
		return true;
	}
}
//*********判断用户名是否正确*********
int Mysql::numpass()
{
	string numpass;
	cout << "请输入账号密码：（用‘-’连接）" << endl;
	cin >> numpass;
	ifstream in("C:\\Users\\12230\\Documents\\vsc++\\new\\id.txt");
	string line;
	if (in) // 有该文件
	{
		while (getline(in, line)) // line中不包括每行的换行符
		{
			if (numpass == line)
			{
				cout << "账号密码正确!" << endl;
				return 1;

			}
		}
		cout << "账号密码错误请重新输入！" << endl;
		return 0;
	}
	else
		cout << "未找到密码文件" << endl;
	return 0;
}
//**********判断字符串是否全为数字*
bool AllisNum(char str[])
{
	for (int i = 0; i < strlen(str); i++)
	{
		int tmp = (int)str[i];
		if (tmp >= 48 && tmp <= 57)
			continue;
		else
			return false;
	}
	return true;
}
