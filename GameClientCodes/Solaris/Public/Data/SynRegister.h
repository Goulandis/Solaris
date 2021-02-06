#pragma once

#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynRegister.generated.h"

UCLASS()
class SOLARIS_API USynRegister : public USynBase
{
	GENERATED_BODY()
public:
	USynRegister();
	void Respond(TArray<FString> dataArr) override;
	virtual void Request(TArray<uint8> buff) override;
};
