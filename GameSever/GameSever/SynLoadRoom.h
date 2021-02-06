#pragma once

#include "Room.h"
#include "SynBase.h"

class SynLoadRoom : public SynBase
{
private:
	Room* room;
public:
	SynLoadRoom();
	void Respond(SOCKET sock, string* dataArr) override;
};

