// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "CafeSdkBlueprintLibrary.h"
#include "CafeSdkInterface.h"


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

void UCafeSdkBlueprintLibrary::InitGlobal(FString ClientId, int32 CommunityId, FString DefaultChannelCode)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->InitGlobal(ClientId, CommunityId, DefaultChannelCode);
}

void UCafeSdkBlueprintLibrary::StartHome()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartHome();
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

void UCafeSdkBlueprintLibrary::StartMenu()
{
    if (!IsSupportedOSVersion()) return;
    GetSharedCafeSdk()->StartMenu();
}

void UCafeSdkBlueprintLibrary::StartMenuById(int32 MenuId)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartMenuById(MenuId);
}

void UCafeSdkBlueprintLibrary::StartProfile()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartProfile();
}

void UCafeSdkBlueprintLibrary::StartWrite(int32 MenuId, FString Subject, FString Text)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartWrite(MenuId, Subject, Text);
}

void UCafeSdkBlueprintLibrary::StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartImageWrite(MenuId, Subject, Text, ImageUri);
}

void UCafeSdkBlueprintLibrary::StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartVideoWrite(MenuId, Subject, Text, VideoUri);
}

void UCafeSdkBlueprintLibrary::StartMore()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StartMore();
}

void UCafeSdkBlueprintLibrary::StartWriteFromScreenshot()
{
    if (!IsCafeSdkAvailable()) return;
    FScreenshotRequest::RequestScreenshot("CafeSdkScreenshot.png", false, false);
}

void UCafeSdkBlueprintLibrary::ShowWidgetWhenUnloadSdk(bool bUse)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->ShowWidgetWhenUnloadSdk(bUse);
}

void UCafeSdkBlueprintLibrary::StopWidget()
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->StopWidget();
}

void UCafeSdkBlueprintLibrary::SetUseVideoRecord(bool bUse)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->SetUseVideoRecord(bUse);
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

void UCafeSdkBlueprintLibrary::SetXButtonType(EXButtonType Type)
{
    if (!IsCafeSdkAvailable()) return;
    bool bUse = Type == EXButtonType::kXButtonTypeClose;
    GetSharedCafeSdk()->SetXButtonTypeClose(bUse);
}

bool UCafeSdkBlueprintLibrary::IsSupportedOSVersion()
{
    return GetSharedCafeSdk()->IsSupportedAndroidVersion();
}
