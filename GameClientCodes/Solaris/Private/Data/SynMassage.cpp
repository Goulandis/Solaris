#include "SynMassage.h"

USynMassage::USynMassage()
{
	flag = SynFlag::SendMassage;
}

void USynMassage::Respond(TArray<FString> dataArr)
{
	
	if ((SynFlag)FCString::Atoi(*dataArr[0]) == flag && (RespondFlag)FCString::Atoi(*dataArr[1]) == RespondFlag::Success)
	{		
		sendFlag = true;
		UE_LOG(LogTemp, Error, TEXT("sendFlag=True"));
		if (dataArr.Num() == 4)
		{
			UE_LOG(LogTemp, Error, TEXT("flagTrue=True"));
			flagSure = true;
			name = dataArr[2];
			massage = dataArr[3];
		}	
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("USynMassage.cpp:Server command code mismacth"));
	}
}
