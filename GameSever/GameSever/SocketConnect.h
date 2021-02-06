#pragma once
#pragma comment(lib,"ws2_32.lib")

#include <winsock2.h>
#include "SocketClientManager.h"
#include "SocketDataReceive.h"

using namespace std;

class SocketConnect
{
public:
	WSADATA wsd;
	SOCKET serverSocket;
	SOCKET clientSocket;
	SOCKADDR_IN addr;

public:
	SocketConnect(int port);
	~SocketConnect();

	SOCKET Listen();
	SOCKET Receive(SocketClientManager& manager);
};

