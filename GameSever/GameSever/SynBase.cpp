#include "SynBase.h"

SocketSingleDataSend SynBase::singleSend =  SocketSingleDataSend();
SocketMultiDataSend SynBase::multiSend = SocketMultiDataSend();

SynBase::SynBase()
{
	sql = new SQL();
}

void SynBase::Send(SOCKET sock, string msg)
{
	int len = msg.copy(buff, msg.length());
	buff[len] = '\0';
	singleSend.Send(sock, buff);
}

void SynBase::Respond(SOCKET sock, string * dataArr)
{
}
