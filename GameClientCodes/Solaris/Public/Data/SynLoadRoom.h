#pragma once

#include "LocalData/RoomItem.h"
#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynLoadRoom.generated.h"

UCLASS(BlueprintType)
class SOLARIS_API USynLoadRoom : public USynBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "SynLoadRoom")
	TArray<URoomItem*> roomList;

public:
	USynLoadRoom();
	void Respond(TArray<FString> dataArr) override;
	float FormPercentage(int win,int total);
};
