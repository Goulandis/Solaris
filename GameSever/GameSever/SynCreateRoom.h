#pragma once

#include "SynBase.h"
#include "Room.h"

class SynCreateRoom : public SynBase
{
public:
	SynCreateRoom();
	void Respond(SOCKET sock, string* dataArr) override;
};

