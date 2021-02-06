#include "SocketMultiDataSend.h"

void SocketMultiDataSend::Send(SOCKET sock1, SOCKET sock2, string msg)
{
	char buff1[BUFFLEN];
	int len1 = msg.copy(buff1, msg.length());
	buff1[len1] = '\0';
	send(sock1, buff1, strlen(buff1) + 1, 0);
	char buff2[BUFFLEN];
	int len2 = msg.copy(buff2, msg.length());
	buff2[len2] = '\0';
	send(sock2, buff2, strlen(buff2) + 1, 0);
}
