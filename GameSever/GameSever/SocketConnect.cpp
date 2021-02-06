#include "SocketConnect.h"
#include <iostream>

SocketConnect::SocketConnect(int port)
{
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "初始化套接字动态库出错" << endl;
		return;
	}
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET)
	{
		cout << "套接字创建失败" << endl;
		WSACleanup();
		return;
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;

	if (bind(serverSocket, (LPSOCKADDR)&addr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		cout << "套接字绑定失败" << endl;
		closesocket(serverSocket);
		WSACleanup();
		return;
	}
}

SocketConnect::~SocketConnect()
{
}

SOCKET SocketConnect::Listen()
{
	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		cout << "监听时发生错误" << endl;
		closesocket(serverSocket);
		WSACleanup();
		return NULL;
	}
	sockaddr_in clientAddr;
	int clientAddrLen = sizeof(clientAddr);
	SOCKET clientSocket = accept(serverSocket, (sockaddr FAR*)&clientAddr, &clientAddrLen);
	if (clientSocket == INVALID_SOCKET)
	{
		cout << "接受客户端时发生错误" << endl;
		closesocket(serverSocket);
		WSACleanup();
		return NULL;
	}
	cout << "客户端 '" << clientSocket << "' 已连接" << endl;
	return clientSocket;
}


SOCKET SocketConnect::Receive(SocketClientManager& manager)
{
	SOCKET sock = Listen();
	if (find(manager.clientList.begin(), manager.clientList.end(), sock) != manager.clientList.end())
	{
		cout << "套接字已存在" << endl;
		return NULL;
	}
	manager.clientList.push_back(sock);
	return sock;
}


