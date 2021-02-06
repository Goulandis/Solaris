#include "SynMiniMapLocation.h"

SynMiniMapLocation::SynMiniMapLocation()
{
	flag = SynFlag::MiniMapLocation;
}

void SynMiniMapLocation::Respond(SOCKET sock, string * dataArr)
{
	if ((SynFlag)atoi(dataArr[0].c_str()) == flag)
	{
		int id = atoi(dataArr[1].c_str());
		string x = dataArr[2];
		string y = dataArr[3];
		RoomItem* item = Room::InstanceRoom()->GetRoom(id);
		string data = to_string(SynFlag::MiniMapLocation) + "," + x + "," + y;
		if (!item)
		{
			cout << "·¿¼äÎ´ÕÒµ½" << endl;
		}
		if (item->ower->sock == sock)
		{
			singleSend.Send(item->other->sock, data);
		}
		if (item->other->sock == sock)
		{
			singleSend.Send(item->ower->sock, data);
		}
	}
}
