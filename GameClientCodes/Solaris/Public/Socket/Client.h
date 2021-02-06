#pragma once

#include "LocalData/LocalRoom.h"
#include "LoadFileContent.h"
#include "FlagLib.h"
#include "Data/DataManager.h"
#include "FSocketDataReceive.h"
#include "Runtime/NEtworking/Public/Networking.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Client.generated.h"

UCLASS()
class SOLARIS_API UClient : public UGameInstance
{
	GENERATED_BODY()
private:
	FRunnableThread* recvThread = nullptr;
	FSocketDataReceive* recv;
public:
	FSocket* connectSocket;
	FIPv4Address ip;
	UPROPERTY(BlueprintReadWrite, Category = "Client")
	UDataManager* dataManager;
	UPROPERTY(BlueprintReadWrite, Category = "Tool")
	ULoadFileContent* loadContent;
	UPROPERTY(BlueprintReadWrite, Category = "Tool")
	ULocalRoom* room;
public:
	UClient();
	~UClient();

	UFUNCTION(BlueprintCallable, Category = "Socket")
	bool Connect(FString ip, int32 port);
	UFUNCTION(BlueprintCallable, Category = "Socket")
	void Send(FString msg);
	UFUNCTION(BlueprintCallable, Category = "Socket")
	void Receive();

	void IsValidDataManager();

	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestRegister(FString userName, FString passwd);
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestLogin(FString userName, FString passwd);
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestLoadRoom();
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestCreateRoom(FString owerName);
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestJionRoom(FString owerName,FString otherName);
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestExitRoom(FString owerName,FString otherName);
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestDismissRoom(FString owerName);
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestStartGame(FString owerName);
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestSendMassage(FString id ,FString msg);
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestCountdown(FString id);
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestRoadMessage(FString id,TargetPoint targetIsTrue);
	UFUNCTION(BlueprintCallable, Category = "Data")
	void RequestMiniMapLocation(FString id, FVector2D playerLocation);
};

