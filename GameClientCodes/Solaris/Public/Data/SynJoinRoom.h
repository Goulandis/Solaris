#pragma once

#include "RoomItem.h"
#include "LocalData/LocalRoom.h"
#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynJoinRoom.generated.h"

UCLASS()
class SOLARIS_API USynJoinRoom : public USynBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "SynJoinRoom")
	ULocalRoom* room;
public:
	USynJoinRoom();
	void Respond(TArray<FString> dataArr) override;
	void SaveRecord(UPlayerData *playerData, int id, FString name, int32 win, int32 total);
};
