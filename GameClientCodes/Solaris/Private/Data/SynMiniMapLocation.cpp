#include "SynMiniMapLocation.h"

USynMiniMapLocation::USynMiniMapLocation()
{
	flag = SynFlag::MiniMapLocation;
}

void USynMiniMapLocation::Respond(TArray<FString> dataArr)
{
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		flagSure = true;
		synLocation.X = FCString::Atof(*dataArr[1]);
		synLocation.Y = FCString::Atof(*dataArr[2]);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynExitRoom.cpp:Server command code mismacth"));
	}
}
