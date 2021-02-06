#include "LocalRoom.h"
#include "..\..\Public\LocalData\LocalRoom.h"

ULocalRoom* ULocalRoom::room = NULL;

ULocalRoom::ULocalRoom()
{
	ower = NewObject<UPlayerData>();
	other = NewObject<UPlayerData>();
	nilPlayer = NewObject<UPlayerData>();
}

ULocalRoom * ULocalRoom::LocalRoomInstance()
{
	if (!room)
	{
		room = NewObject<ULocalRoom>();
	}
	return room;
}
