#include "SynExitRoom.h"

SynExitRoom::SynExitRoom()
{
	flag = SynFlag::ExitRoom;
}

void SynExitRoom::Respond(SOCKET sock, string * dataArr)
{
	if ((SynFlag)atoi(dataArr[0].c_str()) == flag)
	{
		string owerName = dataArr[1];
		string otherName = dataArr[2];
		Room::InstanceRoom()->ExitRoom(owerName, otherName);
	}
	else
	{
		cout << "SynLoadRoom.cpp:客户端请求代码不匹配" << endl;
	}
}
