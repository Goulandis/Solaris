#include "SynExitRoom.h"

USynExitRoom::USynExitRoom()
{
	flag = SynFlag::ExitRoom;
}

void USynExitRoom::Respond(TArray<FString> dataArr)
{
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		flagSure = true;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynExitRoom.cpp:Server command code mismacth"));
	}
}
