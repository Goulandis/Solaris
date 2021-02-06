#include "SynCountdown.h"

int SynCountdown::countdownTime = 20;

SynCountdown::SynCountdown()
{
	flag = SynFlag::Countdown;
}

void SynCountdown::Respond(SOCKET sock, string * dataArr)
{
	if ((SynFlag)atoi(dataArr[0].c_str()) == flag)
	{
		int id = atoi(dataArr[1].c_str());
		RoomItem* item = Room::InstanceRoom()->GetRoom(id);
		if (sock == item->ower->sock)
		{
			item->ower->readyState = true;
		}
		if (sock == item->other->sock)
		{
			item->other->readyState = true;
		}
		while(!item->ower->readyState || !item->other->readyState)
		{
			Sleep(1000);
		} 
		if (sock == item->ower->sock)
		{
			thread clientThread(Countdown, sock, item);
			clientThread.detach();
		}	
	}
}

void SynCountdown::Countdown(SOCKET sock, RoomItem * item)
{
	for (int i = countdownTime; i >= 0; i--)
	{
		string data = to_string(SynFlag::Countdown) + "," + to_string(i);
		multiSend.Send(item->ower->sock, item->other->sock, data);
		Sleep(1000);
	}
	return;
}
