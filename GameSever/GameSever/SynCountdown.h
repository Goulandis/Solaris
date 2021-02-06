#pragma once
#include "SynBase.h"
#include <thread>

class SynCountdown : public SynBase
{
public:
	static int countdownTime;
public:
	SynCountdown();
	void Respond(SOCKET sock, string* dataArr) override;
	static void Countdown(SOCKET sock, RoomItem* item);
};

