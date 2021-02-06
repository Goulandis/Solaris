#pragma once

#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynOtherExitRoom.generated.h"


UCLASS()
class SOLARIS_API USynOtherExitRoom : public USynBase
{
	GENERATED_BODY()
public:
	USynOtherExitRoom();
	void Respond(TArray<FString> dataArr) override;
};
