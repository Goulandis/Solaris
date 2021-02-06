#pragma once

#include "AllowWindowsPlatformTypes.h"
#include <windows.h>
#include <wchar.h>
#include "HideWindowsPlatformTypes.h"
#include "FlagLib.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SynBase.generated.h"

UCLASS(BlueprintType)
class SOLARIS_API USynBase : public UObject
{
	GENERATED_BODY()
	public:
		SynFlag flag = SynFlag::NoneSynFlag;
		UPROPERTY(BlueprintReadWrite,Category="SynBase")
		bool flagSure = false;
		UPROPERTY(BlueprintReadWrite, Category = "SynBase")
		bool sendFlag = false;
	public:
		virtual void Respond(TArray<FString> dataArr);
		virtual void Request(TArray<uint8> buff);
		virtual FString SynMultiByteToWideChar(FString data);
};
