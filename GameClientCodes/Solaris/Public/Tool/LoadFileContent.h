#pragma once

#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "SharedPointer.h"
#include "Modules/ModuleManager.h"
#include "Public/IImageWrapperModule.h"
#include "Public/IImageWrapper.h"
#include "Engine/Texture2D.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LoadFileContent.generated.h"

UCLASS()
class SOLARIS_API ULoadFileContent : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Tool")
	bool imageExist = false;
	UPROPERTY(BlueprintReadOnly, Category = "Tool")
	bool textExist = false;
	UPROPERTY(BlueprintReadOnly, Category = "Tool")
	FString GameContetntPath;
public:
	ULoadFileContent();
	UFUNCTION(BlueprintCallable, Category = "Tool")
	UTexture2D* LoadImage(const FString &path);
	TArray<FColor> Uint8ToFColor(const TArray<uint8> origin);
	UTexture2D* TextureFromImage(const int32 srcWidth, const int32 srcHeight, const TArray<FColor>);
	UFUNCTION(BlueprintCallable, Category = "Tool")
	FString LoadText(const FString &path);
};
