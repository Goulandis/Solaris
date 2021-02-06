#pragma once

#include "Room.h"
#include "SocketDataReceive.h"
#include "SocketSingleDataSend.h"
#include "SocketMultiDataSend.h"
#include "FlagLib.h"
#include <string>
#include <iostream>
#include "AccountDataTable.h"
#include "SQL.h"

using namespace std;

class SynBase
{
public:
	SynFlag flag = SynFlag::NoneSynFlag;
	static SocketSingleDataSend singleSend;
	static SocketMultiDataSend multiSend;
	char buff[BUFFLEN];
	SQL* sql;
public:
	SynBase();
	virtual void Send(SOCKET sock, string msg);
	virtual void Respond(SOCKET sock, string* dataArr);
};