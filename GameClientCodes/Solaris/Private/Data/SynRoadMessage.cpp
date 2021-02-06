#include "SynRoadMessage.h"

USynRoadMessage::USynRoadMessage()
{
	flag = SynFlag::RoadMessage;
}

void USynRoadMessage::Respond(TArray<FString> dataArr)
{
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		flagSure = true;
		targetIsTrue = (TargetPoint)FCString::Atoi(*dataArr[1]);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynCountdown.cpp:Server command code mismacth"));
	}
}
