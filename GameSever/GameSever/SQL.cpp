#include "SQL.h"

SQL::SQL()
{
	con = mysql_init((MYSQL*)0);
	if (con != NULL && mysql_real_connect(con, dbip, dbuser, dbpasswd, dbname, port, NULL, 0))
	{
		if (mysql_select_db(con, dbname))
		{
			cout << "数据库连接失败" << endl;
		}
		else
		{
			con->reconnect = 1;
			connectState = true;
		}
	}
}

SQL::~SQL()
{
	mysql_free_result(res);
	mysql_close(con);
}


AccountDataTable * SQL::ReadAccountData(string name)
{
	char query[SQLQUERYLEN];
	const char* chrName = name.data();
	sprintf_s(query, "select * from %s where name = \'%s\'", tablename, chrName);
	if (mysql_real_query(con, query, strlen(query)))
	{
		cout << "SQL.cpp:数据库读取失败:" << mysql_error(con) << endl;
	}
	else
	{
		int rowNum = 0;
		res = mysql_store_result(con);
		while (row = mysql_fetch_row(res))
		{
			rowNum++;
			if (mysql_num_fields(res) == 5)
			{
				AccountDataTable* accountData = new AccountDataTable();
				accountData->id = atoi(row[0]);
				accountData->userName = row[1];
				accountData->passwd = row[2];
				accountData->total = atoi(row[3]);
				accountData->win = atoi(row[4]);
				return accountData;
			}
			else
			{
				cout << "SQL.cpp:数据库读取格式出错:"<< mysql_error(con) << endl;
			}
		}
	}
	return NULL;
}

bool SQL::SaveAccountData(string name, string passwd,int total,int win)
{
	char query[SQLQUERYLEN];
	const char* chrName = name.data();
	const char* chrPasswd = passwd.data();
	sprintf_s(query, "insert ignore into %s values(null,\'%s\',\'%s\',%d,%d)", tablename, chrName, chrPasswd,total,win);
	if (mysql_real_query(con, query, strlen(query)))
	{
		cout<<"SQL.cpp:数据插入失败:"<< mysql_error(con) << endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool SQL::SaveGradeData(string name, int total, int win)
{
	char query[SQLQUERYLEN];
	const char* chrName = name.data();
	sprintf_s(query, "update %s set total = %d,win = %d where name = \'%s\'", tablename,total,win, chrName);
	if (mysql_real_query(con, query, strlen(query)))
	{
		cout << "SQL.cpp:数据修改失败" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool SQL::SelectAccount(string name)
{
	char query[SQLQUERYLEN];
	const char* chrName = name.data();
	sprintf_s(query, "select name from %s where name = \'%s\'", tablename, chrName);
	if (mysql_real_query(con, query, strlen(query)))
	{
		cout << "SQL.cpp:数据修改失败" << endl;
		return false;
	}
	else
	{
		if (mysql_store_result(con) == 0)
		{
			return true;
		}
	}
	return false;
}
