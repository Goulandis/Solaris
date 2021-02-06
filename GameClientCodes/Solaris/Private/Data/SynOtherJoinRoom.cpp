#include "SynOtherJoinRoom.h"

USynOtherJoinRoom::USynOtherJoinRoom()
{
	flag = SynFlag::OtherJoinRoom;
	room = ULocalRoom::LocalRoomInstance();
}

void USynOtherJoinRoom::Respond(TArray<FString> dataArr)
{

	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		flagSure = true;
		TArray<FString> splitArr;
		dataArr[1].ParseIntoArray(splitArr, TEXT("."), false);
		SaveRecord(FCString::Atoi(*splitArr[0]), splitArr[1], FCString::Atoi(*splitArr[2]), FCString::Atoi(*splitArr[3]));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynOtherJoinRoom.cpp:Server command code mismacth"));
	}
}

void USynOtherJoinRoom::SaveRecord(int32 id, FString name, int32 win, int32 total)
{
	room->id = id;
	room->other->name = name;
	room->other->win = FormPercentage(win, total);
	room->other->total = total;
}

float USynOtherJoinRoom::FormPercentage(int win, int total)
{
	return (round(((float)win / total) * 100) / 100) * 100;
}
