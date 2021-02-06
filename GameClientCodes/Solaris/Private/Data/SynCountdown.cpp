#include "SynCountdown.h"

USynCountdown::USynCountdown()
{
	flag = SynFlag::Countdown;
}

void USynCountdown::Respond(TArray<FString> dataArr)
{
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		flagSure = true;
		countdownTime = dataArr[1];
		UE_LOG(LogTemp, Error, TEXT("%s"),*countdownTime);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynCountdown.cpp:Server command code mismacth"));
	}
}
