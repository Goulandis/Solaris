#include "Room.h"
#include "SQL.h"
#include "AccountDataTable.h"


Room* Room::room = NULL;
HANDLE Room::roomMutex = CreateMutex(nullptr, FALSE, nullptr);

Room::Room()
{
	singleSend = new SocketSingleDataSend();
	multiSend = new SocketMultiDataSend();
}

Room * Room::InstanceRoom()
{
	if (!room)
	{
		WaitForSingleObject(roomMutex,INFINITE);
		room = new Room();
		ReleaseMutex(roomMutex);
	}
	return room;
}

void Room::CreateRoom(SOCKET sock, string owerName)
{
	for (vector<RoomItem*>::iterator it = roomList.begin(); it != roomList.end(); it++)
	{
		if ((*it)->ower->name == owerName)
		{		
			string fmsg = to_string(SynFlag::CreateRoom) + "," + to_string(RespondFlag::Fail);
			singleSend->Send(sock, fmsg);
			return;
		}
	}
	RoomItem* item = new RoomItem();
	int len = roomList.size();
	for (int i = 0; i < len; i++)
	{
		if (item->id == roomList[i]->id)
		{
			srand((unsigned)time(NULL));
			item->id = RANDROM(MINID, MAXID);
			i = 0;
		}
	}
	if (!item->ower)
	{
		item->SpawnOwner(sock, owerName);
	}
	//读取数据库
	SQL sql = SQL();
	AccountDataTable* userData = NULL;
	if (sql.connectState)
	{
		userData = sql.ReadAccountData(owerName);
	}
	if (userData)
	{
		item->ower->name = userData->userName;
		item->ower->sock = sock;
		item->ower->win = userData->win;
		item->ower->total = userData->total;
		item->state = RoomState::Wait;
	}
	roomList.push_back(item);
	string owerData = to_string(item->id)+ "." + item->ower->name + "." + to_string(item->ower->win) + "." + to_string(item->ower->total);
	string smsg = to_string(SynFlag::CreateRoom) + "," + to_string(RespondFlag::Success) + "," +owerData;
	singleSend->Send(sock, smsg);
	userData = NULL;
}

void Room::JoinRoom(SOCKET sock, string owerName, string otherName)
{
	for (vector<RoomItem*>::iterator it = roomList.begin(); it != roomList.end(); it++)
	{
		if ((*it)->ower->name == owerName && (*it)->state == RoomState::Wait)
		{
			if (!(*it)->other)
			{
				(*it)->SpawnOther(sock, otherName);
			}		
			(*it)->other->name = otherName;
			(*it)->other->sock = sock;
			//读取数据库
			SQL sql = SQL();
			AccountDataTable* otherSqlData = NULL;
			if (sql.connectState)
			{
				otherSqlData = sql.ReadAccountData(otherName);
			}
			(*it)->other->win = otherSqlData->win;
			(*it)->other->total = otherSqlData->total;
			if(owerName != otherName) (*it)->state = RoomState::Full;
			string owerData = to_string((*it)->id) + "." + (*it)->ower->name + "." + to_string((*it)->ower->win) + "." + to_string((*it)->ower->total);
			string otherData = to_string((*it)->id) + "." + (*it)->other->name + "." + to_string((*it)->other->win) + "." + to_string((*it)->other->total);
			string smsg = to_string(SynFlag::JoinRoom) + "," + to_string(RespondFlag::Success) + "," + owerData+","+otherData;
			singleSend->Send(sock,smsg);
			string msg = to_string(SynFlag::OtherJoinRoom) + "," + otherData;
			singleSend->Send((*it)->ower->sock, msg);
			otherSqlData = NULL;
			return;
		}
	}
	string fmsg = to_string(SynFlag::JoinRoom) + "," + to_string(RespondFlag::Fail);
	singleSend->Send(sock, fmsg);
}

void Room::ExitRoom(string owerName, string otherName)
{
	for (vector<RoomItem*>::iterator it = roomList.begin(); it != roomList.end(); it++)
	{
		if ((*it)->ower->name == owerName && (*it)->state == RoomState::Full && (*it)->other->name == otherName)
		{
			SOCKET otherSock = (*it)->other->sock;
			(*it)->other = NULL;
			(*it)->state = RoomState::Wait;
			string owerMsg = to_string(SynFlag::OtherExitRoom);
			singleSend->Send((*it)->ower->sock, owerMsg);
			string otherMsg = to_string(SynFlag::ExitRoom);
			singleSend->Send(otherSock, otherMsg);
			cout << "ExitRoom" << endl;
		}
	}
}

void Room::DissmissRoom(string owerName)
{
	for (vector<RoomItem*>::iterator it = roomList.begin(); it != roomList.end(); it++)
	{
		if ((*it)->ower->name == owerName)
		{
			SOCKET owerSock;
			SOCKET otherSock;
			if ((*it)->ower && (*it)->other)
			{
				owerSock = (*it)->ower->sock;
				otherSock = (*it)->other->sock;
				roomList.erase(it);
				multiSend->Send(owerSock, otherSock, to_string(SynFlag::DismissRoom));
			}
			else if ((*it)->ower && !(*it)->other)
			{
				owerSock = (*it)->ower->sock;
				roomList.erase(it);
				singleSend->Send(owerSock, to_string(SynFlag::DismissRoom));
			}
			else
			{
				cout << "Room.cpp/DismissRoom:房间出错" << endl;
			}
			return;
		}
	}
}

void Room::GetLoadRoomList(vector<RoomItem*>& loadRoomList)
{
	for (vector<RoomItem*>::iterator it = roomList.begin(); it != roomList.end(); it++)
	{
		if ((*it)->state == RoomState::Wait)
		{
			loadRoomList.push_back(*it);
		}
	}
}

RoomItem * Room::GetRoom(string owerName)
{
	for (vector<RoomItem*>::iterator it = roomList.begin(); it != roomList.end(); it++)
	{
		if ((*it)->ower->name == owerName)
		{
			if ((*it)->other)
			{
				return *it;
			}
			else
			{
				return NULL;
			}
		}
		
	}
}

RoomItem * Room::GetRoom(int id)
{
	for (vector<RoomItem*>::iterator it = roomList.begin(); it != roomList.end(); it++)
	{
		if ((*it)->id == id)
		{
			return *it;
		}
	}
	return NULL;
}
