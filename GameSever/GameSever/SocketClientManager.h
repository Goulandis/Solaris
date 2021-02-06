#pragma once

#include <vector>
#include <winsock2.h>
#include <iostream>

using namespace std;

class SocketClientManager
{
public:
	vector<SOCKET> clientList;

public:
	void ReflashConnect();
};

