#pragma once

#include "LocalData/LocalRoom.h"
#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynCreateRoom.generated.h"

UCLASS()
class SOLARIS_API USynCreateRoom : public USynBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "SynCreateRoom")
	ULocalRoom* room;
public:
	USynCreateRoom();
	void Respond(TArray<FString> dataArr) override;
	void SaveRecord(int32 id, FString name, int32 win, int32 total);
	float FormPercentage(int win, int total);
};
