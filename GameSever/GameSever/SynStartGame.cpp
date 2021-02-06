#include "SynStartGame.h"

SynStartGame::SynStartGame()
{
	flag = SynFlag::StartGame;
}

void SynStartGame::Respond(SOCKET sock, string * dataArr)
{
	if ((SynFlag)atoi(dataArr[0].c_str()) == flag)
	{
		cout << "StartGame:" << dataArr[1] << endl;
		string owerName = dataArr[1];
		RoomItem* item = Room::InstanceRoom()->GetRoom(owerName);
		if (item && item != NULL)
		{
			string smsg = to_string(SynFlag::StartGame) + "," + to_string(RespondFlag::Success);
			multiSend.Send(sock, item->other->sock, smsg);
		}
		else if (item == NULL)
		{
			string fmsg = to_string(SynFlag::StartGame) + "," + to_string(RespondFlag::Fail);
			singleSend.Send(sock, fmsg);
		}
	}
}
