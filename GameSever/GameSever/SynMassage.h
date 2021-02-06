#pragma once
#include "SynBase.h"
class SynMassage : public SynBase
{
public:
	SynMassage();
	void Respond(SOCKET sock, string* dataArr) override;
};

