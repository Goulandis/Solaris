#include "SynCreateRoom.h"

USynCreateRoom::USynCreateRoom()
{
	flag = SynFlag::CreateRoom;
	room =ULocalRoom::LocalRoomInstance();
}

void USynCreateRoom::Respond(TArray<FString> dataArr)
{
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		if ((SynFlag)FCString::Atoi(*dataArr[1]) == RespondFlag::Success)
		{
			flagSure = true;
			TArray<FString> splitArr;
			dataArr[2].ParseIntoArray(splitArr, TEXT("."), false);
			if (splitArr.Num() != 4)
			{
				UE_LOG(LogTemp, Error, TEXT("SynCreateRoom.cpp:Received server's code error"));
			}
			SaveRecord(FCString::Atoi(*splitArr[0]), splitArr[1], FCString::Atoi(*splitArr[2]), FCString::Atoi(*splitArr[3]));
		}
		if ((SynFlag)FCString::Atoi(*dataArr[1]) == RespondFlag::Fail)
		{
			flagSure = false;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynCreateRoom.cpp:Server command code mismacth"));
	}
}

void USynCreateRoom::SaveRecord(int32 id,FString name,int32 win, int32 total)
{
	room->roomId = id;
	room->ower->name = name;
	room->ower->win = FormPercentage(win, total);
	room->ower->total = total;
}

float USynCreateRoom::FormPercentage(int win, int total)
{
	return (round(((float)win / total) * 100) / 100)*100;
}
