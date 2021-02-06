#pragma once
#include "SynBase.h"
class SynStartGame : public SynBase
{
public:
	SynStartGame();
	void Respond(SOCKET sock, string* dataArr) override;
};

