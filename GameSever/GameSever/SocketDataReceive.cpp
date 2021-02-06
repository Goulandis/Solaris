#include "SocketDataReceive.h"
#include <stdio.h>

char* SocketDataReceive::Receive(SOCKET sock)
{	
	int disConn = 0;
	InitBuff();
	if (recv(sock, buff, BUFFLEN, 0) == 0)
	{
		cout << "消息接受失败" << endl;
		return NULL;
	}
	return buff;
}

void SocketDataReceive::InitBuff()
{
	for (int i = 0; i < BUFFLEN; i++)
	{
		buff[i] = NULL;
	}
}

int SocketDataReceive::GetBuffLen()
{
	int i = 0;
	while (buff[i] != NULL)
	{
		i++;
	}
	return i;
}
