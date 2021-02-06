#pragma once
#include "SynBase.h"
class SynMiniMapLocation : public SynBase
{
public:
	SynMiniMapLocation();
	void Respond(SOCKET sock, string* dataArr) override;
};

