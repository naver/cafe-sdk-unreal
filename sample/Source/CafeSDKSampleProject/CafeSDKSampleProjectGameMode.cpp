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
        
        FCafeSDKPluginModule::OnCafeSdkStarted.AddUObject(this,
            &ACafeSDKSampleProjectGameMode::OnCafeSdkStarted);
        
        FCafeSDKPluginModule::OnCafeSdkStopped.AddUObject(this,
            &ACafeSDKSampleProjectGameMode::OnCafeSdkStopped);
        
        FCafeSDKPluginModule::OnCafeSdkClickAppSchemeBanner.AddUObject(this,
            &ACafeSDKSampleProjectGameMode::OnCafeSdkClickAppSchemeBanner);
        
        FCafeSDKPluginModule::OnCafeSdkJoined.AddUObject(this,
            &ACafeSDKSampleProjectGameMode::OnCafeSdkJoined);
        
        FCafeSDKPluginModule::OnCafeSdkPostedArticle.AddUObject(this,
            &ACafeSDKSampleProjectGameMode::OnCafeSdkPostedArticle);
        
        FCafeSDKPluginModule::OnCafeSdkPostedComment.AddUObject(this,
            &ACafeSDKSampleProjectGameMode::OnCafeSdkPostedComment);
    }
}

#if PLATFORM_ANDROID

#include "Android/AndroidJavaMessageBox.h"

void ShowMessage(FString Message)
{
    if (FTaskGraphInterface::IsRunning())
    {
        FEvent* Event = FPlatformProcess::GetSynchEventFromPool();
        
        FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
        {
            FJavaAndroidMessageBox MessageBox;
            MessageBox.SetText(Message);
            MessageBox.AddButton("ok");
            MessageBox.Show();
        }, TStatId(), NULL, ENamedThreads::GameThread);
        
        FTaskGraphInterface::Get().TriggerEventWhenTaskCompletes(Event, Task, ENamedThreads::GameThread);
    }
}

#else

void ShowMessage(FString Message)
{
    // do nothing.
}

#endif

void ACafeSDKSampleProjectGameMode::OnCafeSdkStarted()
{
    ShowMessage("OnCafeSdkStarted");
}

void ACafeSDKSampleProjectGameMode::OnCafeSdkStopped()
{
    ShowMessage("OnCafeSdkStopped");
}

void ACafeSDKSampleProjectGameMode::OnCafeSdkClickAppSchemeBanner(const FString& AppScheme)
{
    FString Message = FString::Printf(TEXT("OnCafeSdkClickAppSchemeBanner: %s"), *AppScheme);
    ShowMessage(Message);
}

void ACafeSDKSampleProjectGameMode::OnCafeSdkJoined()
{
    ShowMessage("OnCafeSdkJoined");
}

void ACafeSDKSampleProjectGameMode::OnCafeSdkPostedArticle(int32 MenuId)
{
    FString Message = FString::Printf(TEXT("OnCafeSdkPostedArticle: %d"), MenuId);
    ShowMessage(Message);
}

void ACafeSDKSampleProjectGameMode::OnCafeSdkPostedComment(int32 ArticleId)
{
    FString Message = FString::Printf(TEXT("OnCafeSdkPostedComment: %d"), ArticleId);
    ShowMessage(Message);
}
