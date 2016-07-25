// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "CafeSDKSampleProjectGameMode.generated.h"

ENGINE_API DECLARE_LOG_CATEGORY_EXTERN(LogCafeSdk, Log, Warning);

UCLASS()
class CAFESDKSAMPLEPROJECT_API ACafeSDKSampleProjectGameMode : public AGameMode
{
	GENERATED_BODY()
	
    virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
    
    void OnCafeSdkStarted();
    void OnCafeSdkStopped();
    void OnCafeSdkClickAppSchemeBanner(const FString& AppScheme);
    void OnCafeSdkJoined();
    void OnCafeSdkPostedArticle(int32 MenuId, int32 ImageCount, int32 VideoCount);
    void OnCafeSdkPostedComment(int32 ArticleId);
    void OnCafeSdkRecordFinish(const FString& FileUri);
    void OnCafeSdkDidVote(int32 ArticleId);
    
    void OnScreenshotCaptured(int32 Width, int32 Height, const TArray<FColor>& Colors);
};
