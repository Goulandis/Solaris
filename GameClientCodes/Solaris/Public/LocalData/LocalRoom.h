// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FlagLib.h"
#include "PlayerData.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocalRoom.generated.h"


UCLASS()
class SOLARIS_API ULocalRoom : public UObject
{
	GENERATED_BODY()
private:
	static ULocalRoom* room;
public:
	UPROPERTY(BlueprintReadWrite, Category = "Room")
	int32 id;
	UPROPERTY(BlueprintReadWrite, Category = "Room")
	int32 roomId;
	UPROPERTY(BlueprintReadWrite, Category = "Room")
	PlayerFlag flag;
	UPROPERTY(BlueprintReadWrite, Category = "Room")
	UPlayerData* ower;
	UPROPERTY(BlueprintReadWrite, Category = "Room")
	UPlayerData* other;
	UPROPERTY(BlueprintReadWrite, Category = "Room")
	UPlayerData* nilPlayer;
public:
	ULocalRoom();
	static ULocalRoom* LocalRoomInstance();
};
