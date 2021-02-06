#pragma once
#include "SynBase.h"

class SynDismissRoom : public SynBase
{
public:
	SynDismissRoom();
	void Respond(SOCKET sock, string* dataArr) override;
};

