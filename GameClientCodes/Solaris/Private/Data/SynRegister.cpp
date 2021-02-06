#include "SynRegister.h"

USynRegister::USynRegister()
{
	flag = SynFlag::Register;
}

void USynRegister::Respond(TArray<FString> dataArr)
{
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag)
	{
		if ((RespondFlag)FCString::Atoi(*dataArr[1]) == RespondFlag::Success)
		{
			flagSure = true;
		}
		if ((RespondFlag)FCString::Atoi(*dataArr[1]) == RespondFlag::Fail)
		{
			flagSure = false;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynRegister.cpp:Server command code mismacth"));
	}
}

void USynRegister::Request(TArray<uint8> buff)
{
}
