#include "SynDismissRoom.h"

USynDismissRoom::USynDismissRoom()
{
	flag = SynFlag::DismissRoom;
}

void USynDismissRoom::Respond(TArray<FString> dataArr)
{
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		flagSure = true;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynDismissRoom.cpp:Server command code mismacth"));
	}
}
