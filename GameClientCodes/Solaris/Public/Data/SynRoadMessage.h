#pragma once

#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynRoadMessage.generated.h"

UCLASS()
class SOLARIS_API USynRoadMessage : public USynBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "SynCountdown")
	TargetPoint targetIsTrue;
public:
	USynRoadMessage();
	void Respond(TArray<FString> dataArr) override;
};
