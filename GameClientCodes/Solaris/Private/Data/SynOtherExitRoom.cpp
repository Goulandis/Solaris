#include "SynOtherExitRoom.h"

USynOtherExitRoom::USynOtherExitRoom()
{
	flag = SynFlag::OtherExitRoom;
}

void USynOtherExitRoom::Respond(TArray<FString> dataArr)
{
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		flagSure = true;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynOtherExitRoom.cpp:Server command code mismacth"));
	}
}
