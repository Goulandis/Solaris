#include "SynRegister.h"

SynRegister::SynRegister()
{
	flag = SynFlag::Register;
}

void SynRegister::Respond(SOCKET sock, string * dataArr)
{
	
	if (flag == (SynFlag)atoi(dataArr[0].c_str()));
	{
		string userName = dataArr[1];
		string passwd = dataArr[2];
		//����˻������ݿ�����ͬ�˻�����ע��ɹ�������Register
		if (!sql->SelectAccount(userName))
		{
			if (sql->SaveAccountData(userName, passwd))
			{
				string str = to_string(flag) + "," + to_string(RespondFlag::Success);
				Send(sock, str);
			}
		}
		else
		{
			string str = to_string(flag) + "," + to_string(RespondFlag::Fail);
			Send(sock, str);
		}
	}
}