#pragma once

#include "FlagLib.h"
#include <winsock2.h>
#include <iostream>

using namespace std;

class SocketDataReceive
{
public:
	char buff[BUFFLEN];
public:
	char* Receive(SOCKET sock);
	void InitBuff();
	int GetBuffLen();
};

