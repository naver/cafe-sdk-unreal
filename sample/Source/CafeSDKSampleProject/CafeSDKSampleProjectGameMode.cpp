// Fill out your copyright notice in the Description page of Project Settings.

#include "CafeSDKSampleProject.h"
#include "CafeSDKSampleProjectGameMode.h"
#include "CafeSDKPlugin.h"
#include "CafeSdkBlueprintLibrary.h"

DEFINE_LOG_CATEGORY(LogCafeSDK);

void ACafeSDKSampleProjectGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    AGameMode::InitGame(MapName, Options, ErrorMessage);
    
    if (FCafeSDKPluginModule::IsAvailable())
    {
        UCafeSdkBlueprintLibrary::Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    }
}
