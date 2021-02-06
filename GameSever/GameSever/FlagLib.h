#pragma once

#define BUFFLEN 1024
#define DATAARRLEN 10
#define ROOMLISTLEN 20
#define SLEEPTIME 100

#define MINID 10000
#define MAXID 99999
#define RANDROM(a,b) rand()%(b-a)+a

#define SQLQUERYLEN 500

enum SynFlag
{
	/*0*/NoneSynFlag,
	/*1*/Register,
	/*2*/Login,
	/*3*/LoadRoom,
	/*4*/CreateRoom,
	/*5*/ReFlashRoom,
	/*6*/JoinRoom,
	/*7*/OtherJoinRoom,
	/*8*/ExitRoom,
	/*9*/OtherExitRoom,
	/*10*/DismissRoom,
	/*11*/StartGame,
	/*12*/SendMassage,
	/*13*/Countdown,
	/*14*/RoadMessage,
	/*15*/MiniMapLocation,
	Program,
	Grade,
	Communication,
	EndGame
};

enum RespondFlag
{
	NoRespond,
	Success,
	Fail
};

enum RoomState
{
	Wait,
	Full
};

class FlagLib
{
};

