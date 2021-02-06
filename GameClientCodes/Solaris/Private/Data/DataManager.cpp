#include "DataManager.h"

void UDataManager::DataSplit(TArray<uint8> buff)
{
	if (buff.Num() == 0) return;
	FString msg = FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(buff.GetData())));
	UE_LOG(LogTemp, Error, TEXT("%s"), );
	//Print Msg
	UE_LOG(LogTemp, Error, TEXT("Message:%s"), *msg);
	TArray<FString> splitArr;
	msg.ParseIntoArray(splitArr, TEXT(","), false);
	//Print splitArr[0]
	UE_LOG(LogTemp, Error, TEXT("SynFlag:%s"),*splitArr[0]);
	base = ObjDistribution((SynFlag)FCString::Atoi(*splitArr[0]));
	if(base) base->Respond(splitArr);
	else UE_LOG(LogTemp, Error, TEXT("DataManager.cpp:base is nullptr"));
}

FString UDataManager::DataComposite(SynFlag flag)
{
	return FString::FromInt(flag);
}

FString UDataManager::DataComposite(SynFlag flag, FString msg)
{
	return FString::FromInt(flag) + ',' + msg;
}

USynBase* UDataManager::ObjDistribution(SynFlag flag)
{
	switch (flag)
	{
	case SynFlag::Register:
		if (!IsValid(reg)) reg = NewObject<USynRegister>();
		return reg;
	case SynFlag::Login:
		if (!IsValid(log)) log = NewObject<USynLogin>();
		return log;
	case SynFlag::CreateRoom:
		if (!IsValid(croom)) croom = NewObject<USynCreateRoom>();
		return croom;
	case SynFlag::LoadRoom:
		if (!IsValid(lroom)) lroom = NewObject<USynLoadRoom>();
		return lroom;
	case SynFlag::JoinRoom:
		if (!IsValid(jroom)) jroom = NewObject<USynJoinRoom>();
		return jroom;
	case SynFlag::OtherJoinRoom:
		if (!IsValid(oroom)) oroom = NewObject<USynOtherJoinRoom>();
		return oroom;
	case SynFlag::ExitRoom:
		if (!IsValid(eroom)) eroom = NewObject<USynExitRoom>();
		return eroom;
	case SynFlag::OtherExitRoom:
		if (!IsValid(oeroom)) oeroom = NewObject<USynOtherExitRoom>();
		return oeroom;
	case SynFlag::DismissRoom:
		if (!IsValid(droom)) droom = NewObject<USynDismissRoom>();
		return droom;
	case SynFlag::StartGame:
		if (!IsValid(sgame)) sgame = NewObject<USynStartGame>();
		return sgame;
	case SynFlag::SendMassage:
		if (!IsValid(msg)) msg = NewObject<USynMassage>();
		return msg;
	case SynFlag::Countdown:
		if (!IsValid(cdown)) cdown = NewObject<USynCountdown>();
		return cdown;
	case SynFlag::RoadMessage:
		if (!IsValid(rmsg)) rmsg = NewObject<USynRoadMessage>();
		return rmsg;
	case SynFlag::MiniMapLocation:
		if (!IsValid(mml)) mml = NewObject<USynMiniMapLocation>();
		return mml;
	default:
		return NULL;
	}
}
