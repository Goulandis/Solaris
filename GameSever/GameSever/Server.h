#pragma once

#include <thread>
#include "SocketClientManager.h"
#include "SocketConnect.h"
#include "DataManager.h"
#include "Room.h"

using namespace std;

class Server
{

private:

	static SocketConnect connect;
	static SocketSingleDataSend singleSend;
	static SocketMultiDataSend multiSend;
	static SocketDataReceive receive;
	static SocketClientManager clientManager;
	static DataManager dataManager;
public:
	static int port;
	static Room* room;
public: 
	Server();
	void SetUpServer();
	//clientœﬂ≥Ã
	static void ParamTransfer(SOCKET sock);
};

