#include "SynLogin.h"

USynLogin::USynLogin()
{
	flag = SynFlag::Login;
}

void USynLogin::Respond(TArray<FString> dataArr)
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
		UE_LOG(LogTemp, Error, TEXT("USynLogin.cpp:Server command code mismacth"));
	}
}

void USynLogin::Request(TArray<uint8> buff)
{
}
