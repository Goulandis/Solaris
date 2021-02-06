#pragma once

#include "Player.h"
#include <stdlib.h>
#include "FlagLib.h"
#include <ctime>

class RoomItem
{
public:
	Player* ower;
	Player* other;
	int id;
	RoomState state;
public:
	RoomItem();
	void SpawnOwner(SOCKET sock, string name);
	void SpawnOther(SOCKET sock, string name);
};

