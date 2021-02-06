// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FReceive.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SOLARIS_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	FSocket* connectSocket;
	FIPv4Address ip;
	FRunnableThread* recvThread = nullptr;
public:

	UFUNCTION(BlueprintCallable, Category = "Socket")
		void Receive();
	UFUNCTION(BlueprintCallable, Category = "Socket")
		bool Connect(FString ip, int32 port);
};
