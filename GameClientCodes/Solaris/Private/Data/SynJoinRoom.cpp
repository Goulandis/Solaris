#include "SynJoinRoom.h"

USynJoinRoom::USynJoinRoom()
{
	flag = SynFlag::JoinRoom;
	room = ULocalRoom::LocalRoomInstance();
}

void USynJoinRoom::Respond(TArray<FString> dataArr)
{
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		if ((RespondFlag)FCString::Atoi(*dataArr[1]) == RespondFlag::Success)
		{
			UE_LOG(LogTemp, Error, TEXT("JoinRoom"));
			flagSure = true;
			TArray<FString> owerArr;
			TArray<FString> otherArr;
			dataArr[2].ParseIntoArray(owerArr, TEXT("."), false);
			dataArr[3].ParseIntoArray(otherArr, TEXT("."), false);
			SaveRecord(room->ower, FCString::Atoi(*owerArr[0]), owerArr[1], FCString::Atoi(*owerArr[2]), FCString::Atoi(*owerArr[3]));
			SaveRecord(room->other, FCString::Atoi(*otherArr[0]), otherArr[1], FCString::Atoi(*otherArr[2]), FCString::Atoi(*otherArr[3]));
		}
		if ((RespondFlag)FCString::Atoi(*dataArr[1]) == RespondFlag::Fail)
		{
			flagSure = false;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynJoinRoom.cpp:Server command code mismacth"));
	}
}

void USynJoinRoom::SaveRecord(UPlayerData* playerData, int id, FString name, int32 win, int32 total)
{
	room->roomId = id;
	playerData->name = name;
	playerData->win = win;
	playerData->total = total;
}
