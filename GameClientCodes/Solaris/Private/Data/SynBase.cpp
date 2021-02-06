// Fill out your copyright notice in the Description page of Project Settings.


#include "SynBase.h"

void USynBase::Respond(TArray<FString> dataArr)
{
}

void USynBase::Request(TArray<uint8> buff)
{
}

FString USynBase::SynMultiByteToWideChar(FString data)
{
	char str[BUFFLEN] = { 0 };
	strcpy(str,TCHAR_TO_ANSI(*data));
	int dwNum = MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, NULL, 0);
	wchar_t* widebuff = new wchar_t[dwNum];
	MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, widebuff, dwNum);
	return FString(widebuff);
}
