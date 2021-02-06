#pragma once
#include "SynBase.h"
class SynRoadMessage : public SynBase
{
public:
	SynRoadMessage();
	void Respond(SOCKET sock, string* dataArr) override;
};

