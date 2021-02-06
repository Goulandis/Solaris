#include "PlayerData.h"

void UPlayerData::SetAccount(FString userName, FString passwd)
{
	this->name = userName;
	this->password = passwd;
}

void UPlayerData::SetRecord(int32 winNum, int32 totalNum)
{
	this->win = winNum;
	this->total = totalNum;
}
