#pragma once

#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynExitRoom.generated.h"

UCLASS()
class SOLARIS_API USynExitRoom : public USynBase
{
	GENERATED_BODY()
public:
	USynExitRoom();
	void Respond(TArray<FString> dataArr) override;
};
