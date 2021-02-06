#pragma once
#define BUFFLEN 1024

#include "Data/DataManager.h"
#include "FlagLib.h"
#include "CoreMinimal.h"
#include "Runnable.h"
#include "RunnableThread.h"
#include "Networking/Public/Networking.h"

class SOLARIS_API FSocketDataReceive : public FRunnable
{
private:
	FRunnableThread* thread = nullptr;
	FSocket* sock;
	bool threadRunning;
	UDataManager* dataManager;
public:
	TArray<uint8> buff;
private:
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
public:
	FSocketDataReceive(UDataManager* manager, FSocket* sock);
	~FSocketDataReceive();
};
