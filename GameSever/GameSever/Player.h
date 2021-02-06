#pragma once

#include <string>
#include <winsock2.h>

using namespace std;

class Player
{
public:
	SOCKET sock = 0;
	string name = "";
	int win = 0;
	int total = 0;
	bool readyState = false;
};

