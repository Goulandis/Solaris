#pragma once

#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynLogin.generated.h"

UCLASS()
class SOLARIS_API USynLogin : public USynBase
{
	GENERATED_BODY()
public:
	USynLogin();
	void Respond(TArray<FString> dataArr) override;
	virtual void Request(TArray<uint8> buff) override;
};
