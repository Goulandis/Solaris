#pragma once
#include "SynBase.h"
class SynRegister : public SynBase
{
	public:
		SynRegister();
		void Respond(SOCKET sock, string* dataArr) override;
};

