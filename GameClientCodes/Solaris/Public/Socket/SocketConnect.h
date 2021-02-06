// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Runtime/NEtworking/Public/Networking.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SocketConnect.generated.h"

UCLASS()
class SOLARIS_API USocketConnect : public UObject
{
	GENERATED_BODY()
private:
	FSocket *connectSocket;

public:
	//UPROPERTY(EditAnywhere,Category="IPSet")
	FIPv4Address ip;
	FString msg;
public:
	USocketConnect();
	UFUNCTION(BlueprintCallable, Category = "Socket")
	bool Connect(FString ip, int32 port);
};
