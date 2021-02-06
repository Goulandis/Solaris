#pragma once

#include "CoreMinimal.h"
#include "Networking/Public/Networking.h"
#include "Runnable.h"
#include "RunnableThread.h"

class SOLARIS_API FReceive : public FRunnable
{
private:
	FRunnableThread* thread = nullptr;
	FSocket* sock;
	bool threadRunning;
public:
	TArray<uint8> buff;
private:
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
public:
	FReceive(FSocket* sock);
	~FReceive();
};
