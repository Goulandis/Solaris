#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerData.generated.h"

UCLASS()
class SOLARIS_API UPlayerData : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "LocalDataTable")
	FString name;
	UPROPERTY(BlueprintReadWrite, Category = "LocalDataTable")
	FString password;
	UPROPERTY(BlueprintReadWrite, Category = "LocalDataTable")
	float win;
	UPROPERTY(BlueprintReadWrite, Category = "LocalDataTable")
	int32 total;
public:
	UFUNCTION(BlueprintCallable, Category = "LocalDataTable")
	void SetAccount(FString userName, FString passwd);
	void SetRecord(int32 winNum, int32 totalNum);
};
