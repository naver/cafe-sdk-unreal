// Fill out your copyright notice in the Description page of Project Settings.

#include "CafeSDKSampleProject.h"
#include "CafeSDKSampleProjectGameMode.h"
#include "CafeSDKPlugin.h"
#include "CafeSdkBlueprintLibrary.h"

DEFINE_LOG_CATEGORY(LogCafeSdk);

void ACafeSDKSampleProjectGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    AGameMode::InitGame(MapName, Options, ErrorMessage);
    
    if (FCafeSDKPluginModule::IsAvailable())
    {
        UCafeSdkBlueprintLibrary::Init("U5ZHoj_OStOHOJ8mec_s", "piPHPA9i4E", 28334359);
        
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
        
        GEngine->GameViewport->OnScreenshotCaptured().AddUObject(this,
            &ACafeSDKSampleProjectGameMode::OnScreenshotCaptured);
    }
}

#if PLATFORM_ANDROID

#include "Android/AndroidJavaMessageBox.h"

void ShowMessage(FString Message)
{
//    if (FTaskGraphInterface::IsRunning())
//    {
//        FEvent* Event = FPlatformProcess::GetSynchEventFromPool();
//        
//        FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
//        {
//            FJavaAndroidMessageBox MessageBox;
//            MessageBox.SetText(Message);
//            MessageBox.AddButton("ok");
//            MessageBox.Show();
//        }, TStatId(), NULL, ENamedThreads::GameThread);
//        
//        FTaskGraphInterface::Get().TriggerEventWhenTaskCompletes(Event, Task, ENamedThreads::GameThread);
//    }
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

#include "HighResScreenshot.h"
#include "ImageUtils.h"
void ACafeSDKSampleProjectGameMode::OnScreenshotCaptured(int32 Width, int32 Height, const TArray<FColor>& Colors)
{
    auto Bitmap = TArray<FColor>(Colors);
    GetHighResScreenshotConfig().MergeMaskIntoAlpha(Bitmap);
    
    FIntRect SourceRect(0, 0, GScreenshotResolutionX, GScreenshotResolutionY);
    if (GIsHighResScreenshot)
    {
        SourceRect = GetHighResScreenshotConfig().CaptureRegion;
    }
    
    FString ScreenshotName = FScreenshotRequest::GetFilename();
    
    if (!FPaths::GetExtension(ScreenshotName).IsEmpty())
    {
        ScreenshotName = FPaths::GetBaseFilename(ScreenshotName, false);
        ScreenshotName += TEXT(".png");
    }
    
    // Save the contents of the array to a png file.
    TArray<uint8> CompressedBitmap;
    FImageUtils::CompressImageArray(Width, Height, Bitmap, CompressedBitmap);
    FFileHelper::SaveArrayToFile(CompressedBitmap, *ScreenshotName);
    
#if PLATFORM_ANDROID
    extern FString GFilePathBase;
    FString BasePath = GFilePathBase + TEXT("/UE4Game/") + FApp::GetGameName() + TEXT("/") + FApp::GetGameName() + TEXT("/Saved/Screenshots/");
    FString ScreenshotPath = FPaths::ConvertRelativePathToFull(BasePath, ScreenshotName);
    UCafeSdkBlueprintLibrary::StartImageWrite(-1, "", "", TEXT("file://") + ScreenshotPath);
#elif PLATFORM_IOS
    FString Result = ScreenshotName;
    Result.ReplaceInline(TEXT("../"), TEXT(""));
    Result.ReplaceInline(TEXT(".."), TEXT(""));
    Result.ReplaceInline(FPlatformProcess::BaseDir(), TEXT(""));
    
    FString WritePathBase = FString([NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]) + TEXT("/");
    UCafeSdkBlueprintLibrary::StartImageWrite(-1, "", "", WritePathBase + Result);
#endif
}
