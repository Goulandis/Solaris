#pragma once

#include <winsock2.h>
#include <string>
#include "FlagLib.h"

using namespace std;
class SocketMultiDataSend
{
public:
	void Send(SOCKET sock1, SOCKET sock2, string msg);
};

