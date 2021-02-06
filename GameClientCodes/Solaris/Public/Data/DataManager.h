#pragma once

#include "SynMiniMapLocation.h"
#include "SynRoadMessage.h"
#include "SynCountdown.h"
#include "SynMassage.h"
#include "SynStartGame.h"
#include "SynDismissRoom.h"
#include "SynOtherExitRoom.h"
#include "SynExitRoom.h"
#include "SynOtherJoinRoom.h"
#include "SynJoinRoom.h"
#include "SynLoadRoom.h"
#include "SynCreateRoom.h"
#include "SynLogin.h"
#include "SynRegister.h"
#include "SynBase.h"
#include "FlagLib.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataManager.generated.h"

UCLASS()
class SOLARIS_API UDataManager : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynRegister* reg;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynLogin* log;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynCreateRoom* croom;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynLoadRoom* lroom;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynJoinRoom* jroom;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynOtherJoinRoom* oroom;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynExitRoom* eroom;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynOtherExitRoom* oeroom;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynDismissRoom* droom;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynStartGame* sgame;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynMassage* msg;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynCountdown* cdown;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynRoadMessage* rmsg;
	UPROPERTY(BlueprintReadWrite, Category = "DataManager")
	USynMiniMapLocation* mml;

	UPROPERTY(BlueprintReadWrite,Category="DataManager")
	USynBase* base;
public:
	void DataSplit(TArray<uint8> buff);
	FString DataComposite(SynFlag flag);
	FString DataComposite(SynFlag flag,FString msg);
	USynBase* ObjDistribution(SynFlag flag);
};
