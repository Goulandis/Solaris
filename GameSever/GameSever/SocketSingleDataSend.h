#pragma once

#include <winsock2.h>
#include <string>
#include "FlagLib.h"

using namespace std;

class SocketSingleDataSend
{
public:
	void Send(SOCKET sock, string msg);
};

