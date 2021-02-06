#include "SynLoadRoom.h"

SynLoadRoom::SynLoadRoom()
{
	flag = SynFlag::LoadRoom;
	room = Room::InstanceRoom();
}

void SynLoadRoom::Respond(SOCKET sock, string * dataArr)
{
	if ((SynFlag)atoi(dataArr[0].c_str()) == flag)
	{
		cout << "LoadRoom:" << dataArr[0] << endl;
		vector<RoomItem*> roomList;
		room->GetLoadRoomList(roomList);
		string roomListStr;
		vector<string> roomItemArr;
		for (vector<RoomItem*>::iterator it = roomList.begin(); it != roomList.end(); it++)
		{
			string roomItemStr = to_string((*it)->id) + "." + (*it)->ower->name + "." + to_string((*it)->ower->win) + "." + to_string((*it)->ower->total);
			roomItemArr.push_back(roomItemStr);
		}
		for (vector<string>::iterator it = roomItemArr.begin(); it != roomItemArr.end(); it++)
		{
			if (it + 1 == roomItemArr.end())
			{
				roomListStr += *it;
			}
			else
			{
				roomListStr += *it + "/";
			}
		}
		roomListStr = to_string(SynFlag::LoadRoom) + "," + roomListStr;
		Send(sock, roomListStr);
	}
	else
	{
		cout << "SynLoadRoom.cpp:客户端请求代码不匹配" << endl;
	}
}
