#include "SynStartGame.h"

USynStartGame::USynStartGame()
{
	flag = SynFlag::StartGame;
}

void USynStartGame::Respond(TArray<FString> dataArr)
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
		UE_LOG(LogTemp, Error, TEXT("USynStartGame.cpp:Server command code mismacth"));
	}
}
