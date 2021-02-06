#pragma once

#include "CoreMinimal.h"
#include "Data/SynBase.h"
#include "SynStartGame.generated.h"

UCLASS()
class SOLARIS_API USynStartGame : public USynBase
{
	GENERATED_BODY()
public:
	USynStartGame();
	void Respond(TArray<FString> dataArr) override;
};
