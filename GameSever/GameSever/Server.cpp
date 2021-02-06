#include "Server.h"
#include <chrono>


Server::Server()
{
}
int Server::port = 6688;
Room* Server::room = Room::InstanceRoom();

SocketDataReceive Server::receive = SocketDataReceive();
SocketSingleDataSend Server::singleSend = SocketSingleDataSend();
SocketMultiDataSend Server::multiSend = SocketMultiDataSend();
SocketConnect Server::connect = SocketConnect(port);
SocketClientManager Server::clientManager = SocketClientManager();
DataManager Server::dataManager = DataManager();

void Server::SetUpServer()
{
	while (1)
	{
		clientManager.ReflashConnect();
		SOCKET sock = connect.Receive(clientManager);
		thread clientThread(ParamTransfer, sock);
		clientThread.detach();
	}
}

void Server::ParamTransfer(SOCKET sock)
{
	while (true)
	{
		char* buff = receive.Receive(sock);
		if (!buff)
		{
			cout << "¶ÁÈ¡ÄÚÈÝÎª¿Õ" << endl;
			return;
		}
		dataManager.DataSplit(sock, buff, receive.GetBuffLen());
	}
}