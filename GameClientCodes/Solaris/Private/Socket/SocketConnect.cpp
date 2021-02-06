#include "SocketConnect.h"

USocketConnect::USocketConnect()
{
}

bool USocketConnect::Connect(FString ip, int32 port)
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