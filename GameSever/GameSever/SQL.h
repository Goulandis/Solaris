#pragma once


#include "mysql.h"
#include "AccountDataTable.h"
#include <iostream>
#include "FlagLib.h"

using namespace std;

class SQL
{
private:

	MYSQL* con;
	MYSQL_RES* res;
	MYSQL_ROW row;

	char dbuser[20] = "root";
	char dbpasswd[20] = "root";
	char dbip[20] = "localhost";
	char dbname[20] = "solarissqldata";
	char tablename[40] = "solarissqldata.accountdata";
	int port = 3306;
public:
	bool connectState = false;
	
public:
	SQL();
	~SQL();
	AccountDataTable* ReadAccountData(string name);
	bool SaveAccountData(string name, string passwd,int total = 0, int win = 0);
	bool SaveGradeData(string name,int total, int win);
	bool SelectAccount(string name);
};

