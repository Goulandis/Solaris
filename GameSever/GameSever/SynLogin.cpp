#include "SynLogin.h"

SynLogin::SynLogin()
{
	flag = SynFlag::Login;
}

void SynLogin::Respond(SOCKET sock, string * dataArr)
{
	if (flag == (SynFlag)atoi(dataArr[0].c_str()));
	{
		//账户检测，用户是否存在
		string userName = dataArr[1];
		string passwd = dataArr[2];
		AccountDataTable* userData = sql->ReadAccountData(userName);
		if (userData && userData->passwd == passwd)
		{
			string str = to_string(flag) + "," + to_string(RespondFlag::Success);
			Send(sock, str);
		}
		else
		{
			string str = to_string(flag) + "," + to_string(RespondFlag::Fail);
			Send(sock, str);
		}
		
	}
	
}
