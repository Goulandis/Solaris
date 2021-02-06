#include "SynCreateRoom.h"
#include <chrono>
#include <thread>

SynCreateRoom::SynCreateRoom()
{
	flag = SynFlag::CreateRoom;
}

void SynCreateRoom::Respond(SOCKET sock, string * dataArr)
{
	if (flag == (SynFlag)atoi(dataArr[0].c_str()))
	{
		//创建房间	
		Room* room = Room::InstanceRoom();
		room->CreateRoom(sock, dataArr[1]);
	}
	else
	{
		cout << "SynCreateRoom.cpp:客户端请求代码不匹配" << endl;
	}	
}
