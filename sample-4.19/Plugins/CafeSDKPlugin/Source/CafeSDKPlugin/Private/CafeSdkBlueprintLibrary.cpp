// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "CafeSdkBlueprintLibrary.h"
#include "CafeSdk.h"


UCafeSdkBlueprintLibrary::UCafeSdkBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::Init(FString ClientId, FString ClientSecret, int32 CafeId)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->Init(ClientId, ClientSecret, CafeId);
}

void UCafeSdkBlueprintLibrary::InitGlobal(FString ConsumerKey, FString ConsumerSecret, int32 CommunityId, int32 LoungeNo)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->InitGlobal(ConsumerKey, ConsumerSecret, CommunityId, LoungeNo);
}

void UCafeSdkBlueprintLibrary::SetChannelCode(FString ChannelCode)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->SetChannelCode(ChannelCode);
}

void UCafeSdkBlueprintLibrary::StartHome()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartHome();
}

void UCafeSdkBlueprintLibrary::StartPopup()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartPopup();
}

void UCafeSdkBlueprintLibrary::StartPopupWithId(int32 PopupId)
{
    if (!IsSupportedOSVersion()) return;
    GetSharedCafeSdk()->StartPopupWithId(PopupId);
}

void UCafeSdkBlueprintLibrary::StartNotice()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartNotice();
}

void UCafeSdkBlueprintLibrary::StartEvent()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartEvent();
}

void UCafeSdkBlueprintLibrary::StartMenu(int32 MenuNumber)
{
    if (!IsSupportedOSVersion()) return;
    GetSharedCafeSdk()->StartMenu(MenuNumber);
}

void UCafeSdkBlueprintLibrary::StartProfile()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartProfile();
}

void UCafeSdkBlueprintLibrary::StartWrite()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartWrite();
}

void UCafeSdkBlueprintLibrary::StartImageWrite(FString ImageUri)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartImageWrite(ImageUri);
}

void UCafeSdkBlueprintLibrary::StartVideoWrite(FString VideoUri)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartVideoWrite(VideoUri);
}

void UCafeSdkBlueprintLibrary::StartWriteFromScreenshot()
{
    if (!IsCafeSdkAvailable()) return;
    FScreenshotRequest::RequestScreenshot("CafeSdkScreenshot.png", false, false);
}

void UCafeSdkBlueprintLibrary::StartMore()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartMore();
}

void UCafeSdkBlueprintLibrary::Stop()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->Stop();
}

void UCafeSdkBlueprintLibrary::StartWidget()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartWidget();
}

void UCafeSdkBlueprintLibrary::StopWidget()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StopWidget();
}

void UCafeSdkBlueprintLibrary::ShowWidgetWhenUnloadSdk(bool bUse)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->ShowWidgetWhenUnloadSdk(bUse);
}

void UCafeSdkBlueprintLibrary::SetWidgetStartPosition(bool bIsLeft, int32 HeightPercentage)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->SetWidgetStartPosition(bIsLeft, HeightPercentage);
}

void UCafeSdkBlueprintLibrary::SetUseVideoRecord(bool bUse)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->SetUseVideoRecord(bUse);
}

void UCafeSdkBlueprintLibrary::SetUseScreenShot(bool bUse)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->SetUseScreenShot(bUse);
}

void UCafeSdkBlueprintLibrary::SyncGameUserId(FString GameUserId)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->SyncGameUserId(GameUserId);
}

void UCafeSdkBlueprintLibrary::SetThemeColor(FString ThemeColorCSSString, FString TabBackgroundColorCSSString)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->SetThemeColor(ThemeColorCSSString, TabBackgroundColorCSSString);
}

void UCafeSdkBlueprintLibrary::InitRecord()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->InitRecord();
}

void UCafeSdkBlueprintLibrary::StartRecord()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartRecord();
}

void UCafeSdkBlueprintLibrary::StopRecord()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StopRecord();
}

bool UCafeSdkBlueprintLibrary::IsSupportedOSVersion()
{
    return GetSharedCafeSdk()->IsSupportedOSVersion();
}
