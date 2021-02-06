#pragma once

#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynDismissRoom.generated.h"

UCLASS()
class SOLARIS_API USynDismissRoom : public USynBase
{
	GENERATED_BODY()
public:
	USynDismissRoom();
	void Respond(TArray<FString> dataArr) override;
};
