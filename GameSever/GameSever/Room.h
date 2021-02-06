#pragma once
#pragma comment(lib,"ws2_32.lib")

#include <iostream>
#include <vector>
#include "FlagLib.h"
#include "RoomItem.h"
#include "SocketSingleDataSend.h"
#include "SocketMultiDataSend.h"

using namespace std;

class Room
{
private:
	static Room* room;
	char buff[BUFFLEN];
public:
	vector<RoomItem*> roomList;
	static HANDLE roomMutex;
	SocketSingleDataSend* singleSend;
	SocketMultiDataSend* multiSend;

private:
	Room();
public:
	static Room* InstanceRoom();
	void CreateRoom(SOCKET sock,string owerName);
	void JoinRoom(SOCKET sock,string owerName, string otherName);
	//void LoadRoom(SOCKET sock,)
	void ExitRoom(string owerName,string otherName);
	void DissmissRoom(string owerName);
	void GetLoadRoomList(vector<RoomItem*>& loadRoomList);
	RoomItem* GetRoom(string owerName);
	RoomItem* GetRoom(int id);
};

