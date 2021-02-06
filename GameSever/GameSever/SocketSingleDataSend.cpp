#include "SocketSingleDataSend.h"

void SocketSingleDataSend::Send(SOCKET sock, string msg)
{
	char buff[BUFFLEN];
	int len = msg.copy(buff, msg.length());
	buff[len] = '\0';
	send(sock, buff, strlen(buff)+1, 0);
}
