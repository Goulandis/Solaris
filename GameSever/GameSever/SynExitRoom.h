#pragma once
#include "Room.h"
#include "SynBase.h"
class SynExitRoom : public SynBase
{
public:
	SynExitRoom();
	void Respond(SOCKET sock, string* dataArr) override;
};

