#pragma once

#include "SynMiniMapLocation.h"
#include "SynRoadMessage.h"
#include "SynCountdown.h"
#include "SynMassage.h"
#include "SynStartGame.h"
#include "SynDismissRoom.h"
#include "SynExitRoom.h"
#include "SynJoinRoom.h"
#include "SynLoadRoom.h"
#include "SynCreateRoom.h"
#include "SynLogin.h"
#include "SynRegister.h"
#include "FlagLib.h"
#include "SynBase.h"
#include <string>
#include <winsock2.h>

class DataManager
{
private:
	SynBase* base;

	SynRegister* reg;
	SynLogin* log;
	SynCreateRoom* croom;
	SynLoadRoom* lroom;
	SynJoinRoom* jroom;
	SynExitRoom* eroom;
	SynDismissRoom* droom;
	SynStartGame* sgame;
	SynMassage* msg;
	SynCountdown* cdown;
	SynRoadMessage* rmsg;
	SynMiniMapLocation* mml;
public:
	DataManager();
	void DataSplit(SOCKET sock, char* buff,int len);
	void DataComposite(string msg);
	SynBase* ObjDistribution(SynFlag flag);
};

