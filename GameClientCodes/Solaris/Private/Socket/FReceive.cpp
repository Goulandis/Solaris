#include "FReceive.h"


bool FReceive::Init()
{
	threadRunning = true;
	return true;
}

uint32 FReceive::Run()
{
	if (!sock) return 0;
	int32 readType = 0;
	buff.Init(NULL, 1024u);
	while (threadRunning)
	{
		UE_LOG(LogTemp, Error, TEXT("RUN"));
		sock->Recv(buff.GetData(), buff.Num(), readType);
		if (buff.Num() == 0) break;

		UE_LOG(LogTemp, Error, TEXT("RUNED"));
	}
	return 1;
}

void FReceive::Stop()
{
	threadRunning = false;
	if (thread) thread->WaitForCompletion();
}

FReceive::FReceive(FSocket * sock)
{
	this->sock = sock;
	threadRunning = true;
}

FReceive::~FReceive()
{
	threadRunning = false;
	if (thread) delete thread;
	thread = nullptr;
}
