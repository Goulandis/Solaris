#include "Client.h"


UClient::UClient()
{
	dataManager = NewObject<UDataManager>();
	loadContent = NewObject<ULoadFileContent>();
	room = ULocalRoom::LocalRoomInstance();
	if (Connect("127.0.0.1", 6688))
	{
		UE_LOG(LogTemp, Error, TEXT("Connet"));
		Receive();
	}	
}

UClient::~UClient()
{
	if(recvThread) delete recvThread;
}

bool UClient::Connect(FString ip, int32 port)
{
	FIPv4Address::Parse(ip, this->ip);
	TSharedPtr<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(this->ip.Value);
	addr->SetPort(port);
	connectSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("Default"), false);
	if (!connectSocket->Connect(*addr))
	{
		UE_LOG(LogTemp, Error, TEXT("Server connect fail"));
		return false;
	}
	return true;
}

void UClient::Send(FString msg)
{
	TCHAR* seriallizedChar = msg.GetCharArray().GetData();
	int32 size = FCString::Strlen(seriallizedChar) + 1;
	int32 sent = 0;
	if (!connectSocket->Send((uint8*)TCHAR_TO_UTF8(seriallizedChar), size, sent))
	{
		UE_LOG(LogTemp, Error, TEXT("Message send failly"));
	}
}

void UClient::Receive()
{
	if (IsValid(dataManager))
	{
		dataManager = NewObject<UDataManager>();
	}
	recv = new FSocketDataReceive(dataManager,connectSocket);
}

void UClient::IsValidDataManager()
{
	if (!IsValid(dataManager))
	{
		dataManager = NewObject<UDataManager>();
	}
}

void UClient::RequestRegister(FString userName, FString passwd)
{
	FString data = userName + ',' + passwd;
	IsValidDataManager();
	Send(dataManager->DataComposite(SynFlag::Register, data));
}

void UClient::RequestLogin(FString userName, FString passwd)
{
	FString data = userName + ',' + passwd;
	IsValidDataManager();
	Send(dataManager->DataComposite(SynFlag::Login, data));
}

void UClient::RequestLoadRoom()
{
	IsValidDataManager();
	Send(dataManager->DataComposite(SynFlag::LoadRoom));
}

void UClient::RequestCreateRoom(FString owerName)
{
	FString data = owerName;
	IsValidDataManager();
	Send(dataManager->DataComposite(SynFlag::CreateRoom, data));
}

void UClient::RequestJionRoom(FString owerName, FString otherName)
{
	FString data = owerName + "," + otherName;
	IsValidDataManager();
	Send(dataManager->DataComposite(SynFlag::JoinRoom, data));
}

void UClient::RequestExitRoom(FString owerName, FString otherName)
{
	FString data = owerName + "," + otherName;
	IsValidDataManager();
	Send(dataManager->DataComposite(SynFlag::ExitRoom, data));
}

void UClient::RequestDismissRoom(FString owerName)
{
	IsValidDataManager();
	Send(dataManager->DataComposite(SynFlag::DismissRoom, owerName));
}

void UClient::RequestStartGame(FString owerName)
{
	IsValidDataManager();
	Send(dataManager->DataComposite(SynFlag::StartGame, owerName));
}

void UClient::RequestSendMassage(FString id,FString msg)
{
	IsValidDataManager();
	FString data = id + "," + msg;
	Send(dataManager->DataComposite(SynFlag::SendMassage, data));
}

void UClient::RequestCountdown(FString id)
{
	IsValidDataManager();
	Send(dataManager->DataComposite(SynFlag::Countdown, id));
}

void UClient::RequestRoadMessage(FString id, TargetPoint targetIsTrue)
{
	IsValidDataManager();
	FString data = id +","+ FString::FromInt((int32)targetIsTrue);
	Send(dataManager->DataComposite(SynFlag::RoadMessage, data));
}

void UClient::RequestMiniMapLocation(FString id, FVector2D playerLocation)
{
	IsValidDataManager();
	FString data = id + "," + FString::SanitizeFloat(playerLocation.X) + "," + FString::SanitizeFloat(playerLocation.Y);
	Send(dataManager->DataComposite(SynFlag::MiniMapLocation, data));
}
