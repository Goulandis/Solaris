#pragma once

#include "PlayerData.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoomItem.generated.h"

UCLASS(BlueprintType)
class SOLARIS_API URoomItem : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Room")
	int32 id;
	UPROPERTY(BlueprintReadWrite, Category = "Room")
	UPlayerData* ower;
	UPROPERTY(BlueprintReadWrite, Category = "Room")
	UPlayerData* other;
public:
	URoomItem();
};
