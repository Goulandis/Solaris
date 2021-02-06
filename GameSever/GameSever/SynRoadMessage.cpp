#include "SynRoadMessage.h"

SynRoadMessage::SynRoadMessage()
{
	flag = SynFlag::RoadMessage;
}

void SynRoadMessage::Respond(SOCKET sock, string * dataArr)
{
	if ((SynFlag)atoi(dataArr[0].c_str()) == flag)
	{
		int roomId = atoi(dataArr[1].c_str());
		string msg = dataArr[2];
		RoomItem* item = Room::InstanceRoom()->GetRoom(roomId);
		string data = to_string(SynFlag::RoadMessage) + "," + msg;
		//other线程执行
		if (sock == item->ower->sock)
		{	
			singleSend.Send(item->other->sock, data);
		}
		//ower线程执行
		if (sock == item->other->sock)
		{
			singleSend.Send(item->ower->sock, data);
		}
	}
}
