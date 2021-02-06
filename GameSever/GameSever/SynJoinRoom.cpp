#include "SynJoinRoom.h"

SynJoinRoom::SynJoinRoom()
{
	flag = SynFlag::JoinRoom;
}

void SynJoinRoom::Respond(SOCKET sock, string * dataArr)
{
	if ((SynFlag)atoi(dataArr[0].c_str()) == flag)
	{
		string owerName = dataArr[1];
		string otherName = dataArr[2];
		Room::InstanceRoom()->JoinRoom(sock, owerName, otherName);
	}	
	else
	{
		cout << "SynJoinRoom.cpp:客户端请求代码不匹配" << endl;
	}
}
