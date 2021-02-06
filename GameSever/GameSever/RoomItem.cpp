#include "RoomItem.h"
#include <iostream>

using namespace std;

RoomItem::RoomItem()
{
	srand((unsigned)time(NULL));
	id = RANDROM(MINID,MAXID);
}

void RoomItem::SpawnOwner(SOCKET sock, string name)
{
	if (!ower)
	{
		ower = new Player();
		ower->sock = sock;
		ower->name = name;
	}
}

void RoomItem::SpawnOther(SOCKET sock, string name)
{
	if (!other)
	{
		other = new Player();
		other->sock = sock;
		other->name = name;
	}
}
