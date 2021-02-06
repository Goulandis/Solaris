#pragma once
#include "SynBase.h"
#include "Room.h"
class SynJoinRoom : public SynBase
{
public:
	SynJoinRoom();
	void Respond(SOCKET sock, string* dataArr) override;
};

