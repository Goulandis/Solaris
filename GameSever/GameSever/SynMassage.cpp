#include "SynMassage.h"

SynMassage::SynMassage()
{
	flag = SynFlag::SendMassage;
}

void SynMassage::Respond(SOCKET sock, string * dataArr)
{
	if ((SynFlag)atoi(dataArr[0].c_str()) == flag)
	{
		int roomId = atoi(dataArr[1].c_str());
		string msg = dataArr[2];
		cout << "RoomID:" << roomId << endl;
		RoomItem *item = Room::InstanceRoom()->GetRoom(roomId);
		if (!item->other)
		{
			string fmsg = to_string(SynFlag::SendMassage) + "," + to_string(RespondFlag::Fail);
			singleSend.Send(sock, fmsg); 
			return;
		}
		if (sock == item->ower->sock)
		{
			string sotmsg = to_string(SynFlag::SendMassage) + "," + to_string(RespondFlag::Success) + "," + item->ower->name +"," +  msg;
			string sowmsg = to_string(SynFlag::SendMassage) + "," + to_string(RespondFlag::Success);
			singleSend.Send(item->other->sock, sotmsg);
			singleSend.Send(item->ower->sock, sowmsg);
		}
		if (sock == item->other->sock)
		{
			string sowmsg = to_string(SynFlag::SendMassage) + "," + to_string(RespondFlag::Success) + "," + item->other->name + "," + msg;
			string sotmsg = to_string(SynFlag::SendMassage) + "," + to_string(RespondFlag::Success);
			singleSend.Send(item->ower->sock, sowmsg);
			singleSend.Send(item->other->sock, sotmsg);
		}
	}
}
