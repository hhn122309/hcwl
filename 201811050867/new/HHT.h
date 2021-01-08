#pragma once
#include <iostream>
using namespace std;
class Mysql
{
public:
	Mysql(const char id[20] = "root",const char paw[20] = "1223095464qq");		//¹¹Ôìº¯Êý
	void ConnectDatabase();
	void FreeConnect();
	bool ShowAll();
	bool QueryDatabase(char[], char[]);
	bool InsertData(char e[][150]);
	bool ModifyData(char e[][150]);
	bool DeleteData(char[], char[]);
	bool addnumpass();
	int numpass();
	bool UsePromptPage();
private:
	char use_id[20];
	char use_paw[20];
};
