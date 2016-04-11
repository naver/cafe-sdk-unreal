// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "CafeSDKSampleProjectGameMode.generated.h"

ENGINE_API DECLARE_LOG_CATEGORY_EXTERN(LogCafeSDK, Log, Warning);

UCLASS()
class CAFESDKSAMPLEPROJECT_API ACafeSDKSampleProjectGameMode : public AGameMode
{
	GENERATED_BODY()
	
    virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};
