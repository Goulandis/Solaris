#include "LoadFileContent.h"

ULoadFileContent::ULoadFileContent()
{
	GameContetntPath = FPaths::GameContentDir();
}

UTexture2D* ULoadFileContent::LoadImage(const FString &path)
{
	UTexture2D* outTex = nullptr;
	IImageWrapperModule & imageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	TSharedPtr<IImageWrapper> imageWrapper = imageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
	TArray<uint8> outArray;
	if (FFileHelper::LoadFileToArray(outArray, *path))
	{
		if (imageWrapper.IsValid() && imageWrapper->SetCompressed(outArray.GetData(), outArray.Num()))
		{
			const TArray<uint8>* uncompressedRGBA = NULL;
			if (imageWrapper->GetRaw(ERGBFormat::BGRA, 8, uncompressedRGBA))
			{
				const TArray<FColor> uncompressedFColor = Uint8ToFColor(*uncompressedRGBA);
				outTex = TextureFromImage(imageWrapper->GetWidth(), imageWrapper->GetHeight(), uncompressedFColor);
				imageExist = true;
			}
		}
	}
	else
	{
		imageExist = false;
	}
	return outTex;
}

TArray<FColor> ULoadFileContent::Uint8ToFColor(const TArray<uint8> origin)
{
	TArray<FColor> uncompressedFColor;
	uint8 auxOrigin;
	FColor auxDst;
	for (int32 i = 0; i < origin.Num(); i++)
	{
		auxOrigin = origin[i];
		auxDst.B = auxOrigin;
		i++;
		auxOrigin = origin[i];
		auxDst.G = auxOrigin;
		i++;
		auxOrigin = origin[i];
		auxDst.R = auxOrigin;
		i++;
		auxOrigin = origin[i];
		auxDst.A = auxOrigin;
		uncompressedFColor.Add(auxDst);
	}
	return uncompressedFColor;
}

UTexture2D* ULoadFileContent::TextureFromImage(const int32 srcWidth, const int32 srcHeight, const TArray<FColor> srcData)
{
	UTexture2D* MyScreenshot = UTexture2D::CreateTransient(srcWidth, srcHeight, PF_B8G8R8A8);
	uint8* MipData = static_cast<uint8*>(MyScreenshot->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE));
	uint8* destPtr = NULL;
	const FColor* srcPtr = NULL;
	for (int32 y = 0; y < srcHeight; y++)
	{
		destPtr = &MipData[(srcHeight - 1 - y) * srcWidth * sizeof(FColor)];
		srcPtr = const_cast<FColor*>(&srcData[(srcHeight - 1 - y) * srcWidth]);
		for (int32 x = 0; x < srcWidth; x++)
		{
			*destPtr++ = srcPtr->B;
			*destPtr++ = srcPtr->G;
			*destPtr++ = srcPtr->R;
			*destPtr++ = srcPtr->A;
			srcPtr++;
		}
	}
	MyScreenshot->PlatformData->Mips[0].BulkData.Unlock();
	MyScreenshot->UpdateResource();
	return MyScreenshot;
}

FString ULoadFileContent::LoadText(const FString & path)
{
	FString content = " ";
	if (FFileHelper::LoadFileToString(content, *path))
	{
		UE_LOG(LogTemp, Error, TEXT("text:"),*content);
		textExist = true;
		return content;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("LoadImageFromFile.cpp:File is not exist"));
		textExist = false;
		return content;
	}
}