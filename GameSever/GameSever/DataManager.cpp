#include "DataManager.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

DataManager::DataManager()
{

}

void DataManager::DataSplit(SOCKET sock, char * buff,int len)
{
	//ÏûÏ¢²ğ·Ö
	int size = 1;
	for (int i = 0; i < len; i++)
	{
		if (buff[i] == ',') size++;
	}
	string dataArr[DATAARRLEN];
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		if (buff[i] != ',')
		{
			dataArr[k] += buff[i];
		}
		else
		{	
			if(k<size) k++;
		}
	}
	base = ObjDistribution((SynFlag)atoi(dataArr[0].c_str()));
	if(base!=NULL)base->Respond(sock,dataArr);
	else cout << "DataManager.cpp:base is nullptr" << endl;
}

SynBase* DataManager::ObjDistribution(SynFlag flag)
{
	switch (flag)
	{
	case SynFlag::Register:
		if (!reg) reg = new SynRegister();
		return reg;
	case SynFlag::Login:
		if (!log) log = new SynLogin();
		return log;
	case SynFlag::CreateRoom:
		if (!croom) croom = new SynCreateRoom();
		return croom;
	case SynFlag::LoadRoom:
		if (!lroom)	lroom = new SynLoadRoom();
		return lroom;
	case SynFlag::JoinRoom:
		if (!jroom) jroom = new SynJoinRoom();
		return jroom;
	case SynFlag::ExitRoom:
		if (!eroom) eroom = new SynExitRoom();
		return eroom;
	case SynFlag::DismissRoom:
		if (!droom) droom = new SynDismissRoom();
		return droom;
	case SynFlag::StartGame:
		if (!sgame) sgame = new SynStartGame();
		return sgame;
	case SynFlag::SendMassage:
		if (!msg) msg = new SynMassage();
		return msg;
	case SynFlag::Countdown:
		if (!cdown) cdown = new SynCountdown();
		return cdown;
	case SynFlag::RoadMessage:
		if (!rmsg) rmsg = new SynRoadMessage();
		return rmsg;
	case SynFlag::MiniMapLocation:
		if (!mml) mml = new SynMiniMapLocation();
		return mml;
	default:
		return NULL;
	}
}
