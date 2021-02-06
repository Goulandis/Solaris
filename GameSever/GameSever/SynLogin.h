#pragma once
#include "SynBase.h"
class SynLogin : public SynBase
{
public:
	SynLogin();
	void Respond(SOCKET sock, string* dataArr) override;
};

