#pragma once

#define BUFFLEN 1024

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FlagLib.generated.h"

UENUM()
enum SynFlag
{
	/*0*/NoneSynFlag,
	/*1*/Register,
	/*2*/Login,
	/*3*/LoadRoom,
	/*4*/CreateRoom,
	/*5*/ReFlashRoom,
	/*6*/JoinRoom,
	/*7*/OtherJoinRoom,
	/*8*/ExitRoom,
	/*9*/OtherExitRoom,
	/*10*/DismissRoom,
	/*11*/StartGame,
	/*12*/SendMassage,
	/*13*/Countdown,
	/*14*/RoadMessage,
	/*15*/MiniMapLocation,
	Grade,
	Communication,
	EndGame
};

UENUM()
enum RespondFlag
{
	NoRespond,
	Success,
	Fail
};

UENUM(BlueprintType)
enum class TargetPoint : uint8
{
	Nil,
	PointA,
	PointB
};

UENUM(BlueprintType)
enum class PlayerFlag : uint8
{
	NilPlayer,
	Ower,
	Ohter
};



UCLASS()
class SOLARIS_API UFlagLib : public UObject
{
	GENERATED_BODY()
	
};
