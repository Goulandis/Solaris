#include "RoomItem.h"

URoomItem::URoomItem()
{
	ower = NewObject<UPlayerData>();
	other = NewObject<UPlayerData>();
}
