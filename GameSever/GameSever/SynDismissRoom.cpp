#include "SynDismissRoom.h"

SynDismissRoom::SynDismissRoom()
{
	flag = SynFlag::DismissRoom;
}

void SynDismissRoom::Respond(SOCKET sock, string * dataArr)
{
	if ((SynFlag)atoi(dataArr[0].c_str()) == flag)
	{
		cout << "DismissRoom:" << dataArr[1] << endl;
		string owerName = dataArr[1];
		Room::InstanceRoom()->DissmissRoom(owerName);
	}
	else
	{
		cout << "SynDismissRoom.cpp:客户端请求代码不匹配" << endl;
	}
}
