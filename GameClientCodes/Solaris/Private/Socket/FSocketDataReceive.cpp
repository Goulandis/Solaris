#include "FSocketDataReceive.h"

bool FSocketDataReceive::Init()
{
	threadRunning = true;
	return true;
}

uint32 FSocketDataReceive::Run()
{
	if (!sock) return 0;
	int32 readType = 0;
	while (threadRunning)
	{
		buff.Init(NULL, BUFFLEN);
		sock->Recv(buff.GetData(), buff.Num(), readType); 
		if (buff[0] == NULL) Stop();
		dataManager->DataSplit(buff);
	}
	return 1;
}

void FSocketDataReceive::Stop()
{
	threadRunning = false;
	if (thread)
	{
		thread->WaitForCompletion();
		delete thread;
	}
	thread = nullptr;
}

FSocketDataReceive::FSocketDataReceive(UDataManager* manager, FSocket* sock)
{
	this->sock = sock;
	threadRunning = true;
	dataManager = manager;
	thread = FRunnableThread::Create(this, TEXT("ReceiveThread"), 0);
}

FSocketDataReceive::~FSocketDataReceive()
{
	threadRunning = false;
	if(thread) delete thread;
	thread = nullptr;
}
