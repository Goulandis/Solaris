// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynCountdown.generated.h"

UCLASS()
class SOLARIS_API USynCountdown : public USynBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite,Category = "SynCountdown")
	FString countdownTime;
public:
	USynCountdown();
	void Respond(TArray<FString> dataArr) override;
};
