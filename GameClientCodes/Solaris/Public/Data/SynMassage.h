#pragma once

#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynMassage.generated.h"

UCLASS()
class SOLARIS_API USynMassage : public USynBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "SynMassage")
	FString massage;
	UPROPERTY(BlueprintReadWrite, Category = "SynMassage")
	FString name;

public:
	USynMassage();
	void Respond(TArray<FString> dataArr) override;
};
