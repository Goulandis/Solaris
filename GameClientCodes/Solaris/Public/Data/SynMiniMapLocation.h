#pragma once

#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynMiniMapLocation.generated.h"


UCLASS()
class SOLARIS_API USynMiniMapLocation : public USynBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "USynMiniMapLocation")
	FVector2D synLocation;
public:
	USynMiniMapLocation();
	void Respond(TArray<FString> dataArr) override;
};
