#include "SynLoadRoom.h"

USynLoadRoom::USynLoadRoom()
{
	flag = SynFlag::LoadRoom;
}

void USynLoadRoom::Respond(TArray<FString> dataArr)
{
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		flagSure = true;
		roomList.Empty();
		UE_LOG(LogTemp, Error, TEXT("LoadRoom"));
		TArray<FString> splitArr;
		dataArr[1].ParseIntoArray(splitArr, TEXT("/"), false);
		for (int32 i = 0; i < splitArr.Num(); i++)
		{
			TArray<FString> tmpArr;
			URoomItem* item = NewObject<URoomItem>();
			roomList.Emplace(item);
			splitArr[i].ParseIntoArray(tmpArr, TEXT("."), false);
			if (tmpArr.Num() != 4)
			{
				UE_LOG(LogTemp, Error, TEXT("SynLoadRoom.cpp:Receive server dara error"));
				return;
			}
			roomList[i]->id = FCString::Atoi(*tmpArr[0]);
			roomList[i]->ower->name = tmpArr[1];
			roomList[i]->ower->win = FormPercentage(FCString::Atoi(*tmpArr[2]),FCString::Atoi(*tmpArr[3]));
			roomList[i]->ower->total = FCString::Atoi(*tmpArr[3]);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynLoadRoom.cpp:Server command code mismacth"));
	}
}

float USynLoadRoom::FormPercentage(int win, int total)
{
	return (round(((float)win / total) * 100) / 100) * 100;
}
