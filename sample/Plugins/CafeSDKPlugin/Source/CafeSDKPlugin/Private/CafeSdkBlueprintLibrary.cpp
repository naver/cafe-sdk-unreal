// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "CafeSdkBlueprintLibrary.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJavaGlink.h"
#include "Android/AndroidJavaCafeSdk.h"

UCafeSdkBlueprintLibrary::UCafeSdkBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::Init(FString ClientId, FString ClientSecret, int32 CafeId)
{
    if (!IsSupportedOSVersion()) return;
    GetSharedCafeSdk()->Init(ClientId, ClientSecret, CafeId);
}

void UCafeSdkBlueprintLibrary::StartHome()
{
    if (!IsSupportedOSVersion()) return;
    GetSharedGlink()->StartHome();
}

void UCafeSdkBlueprintLibrary::StartNotice()
{
    if (!IsSupportedOSVersion()) return;
    GetSharedGlink()->StartNotice();
}

void UCafeSdkBlueprintLibrary::StartEvent()
{
    if (!IsSupportedOSVersion()) return;
    GetSharedGlink()->StartEvent();
}

void UCafeSdkBlueprintLibrary::StartMenu()
{
    if (!IsSupportedOSVersion()) return;
    GetSharedGlink()->StartMenu();
}

void UCafeSdkBlueprintLibrary::StartMenuById(int32 MenuId)
{
    if (!IsSupportedOSVersion()) return;
    GetSharedGlink()->StartMenuById(MenuId);
}

void UCafeSdkBlueprintLibrary::StartProfile()
{
    if (!IsSupportedOSVersion()) return;
    GetSharedGlink()->StartProfile();
}

void UCafeSdkBlueprintLibrary::StartWrite(int32 MenuId, FString Subject, FString Text)
{
    if (!IsSupportedOSVersion()) return;
    GetSharedGlink()->StartWrite(MenuId, Subject, Text);
}

void UCafeSdkBlueprintLibrary::StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri)
{
    if (!IsSupportedOSVersion()) return;
    GetSharedGlink()->StartImageWrite(MenuId, Subject, Text, ImageUri);
}

void UCafeSdkBlueprintLibrary::StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri)
{
    if (!IsSupportedOSVersion()) return;
    GetSharedGlink()->StartVideoWrite(MenuId, Subject, Text, VideoUri);
}

void UCafeSdkBlueprintLibrary::StartMore()
{
    if (!IsSupportedOSVersion()) return;
    GetSharedGlink()->StartMore();
}

void UCafeSdkBlueprintLibrary::StartWriteFromScreenshot()
{
    if (!IsSupportedOSVersion()) return;
    FScreenshotRequest::RequestScreenshot("CafeSdkScreenshot.png", false, false);
}

bool UCafeSdkBlueprintLibrary::IsSupportedOSVersion()
{
    return GetSharedGlink()->IsSupportedAndroidVersion();
}

#elif PLATFORM_IOS

#include "IOS/IOSCafeSdk.h"

UCafeSdkBlueprintLibrary::UCafeSdkBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

void UCafeSdkBlueprintLibrary::Init(FString ClientId, FString ClientSecret, int32 CafeId)
{
    GetSharedCafeSdk()->Init(ClientId, ClientSecret, CafeId);
}

void UCafeSdkBlueprintLibrary::StartHome()
{
    GetSharedCafeSdk()->StartHome();
}

void UCafeSdkBlueprintLibrary::StartNotice()
{
    GetSharedCafeSdk()->StartNotice();
}

void UCafeSdkBlueprintLibrary::StartEvent()
{
    GetSharedCafeSdk()->StartEvent();
}

void UCafeSdkBlueprintLibrary::StartMenu()
{
    GetSharedCafeSdk()->StartMenu();
}

void UCafeSdkBlueprintLibrary::StartMenuById(int32 MenuId)
{
    GetSharedCafeSdk()->StartMenuById(MenuId);
}

void UCafeSdkBlueprintLibrary::StartProfile()
{
    GetSharedCafeSdk()->StartProfile();
}

void UCafeSdkBlueprintLibrary::StartWrite(int32 MenuId, FString Subject, FString Text)
{
    GetSharedCafeSdk()->StartWrite(MenuId, Subject, Text);
}

void UCafeSdkBlueprintLibrary::StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri)
{
    GetSharedCafeSdk()->StartImageWrite(MenuId, Subject, Text, ImageUri);
}

void UCafeSdkBlueprintLibrary::StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri)
{
    GetSharedCafeSdk()->StartVideoWrite(MenuId, Subject, Text, VideoUri);
}

void UCafeSdkBlueprintLibrary::StartMore()
{
    GetSharedCafeSdk()->StartMore();
}

void UCafeSdkBlueprintLibrary::StartWriteFromScreenshot()
{
    FScreenshotRequest::RequestScreenshot("CafeSdkScreenshot.png", false, false);
}

bool UCafeSdkBlueprintLibrary::IsSupportedOSVersion()
{
    return false;
}

#else

UCafeSdkBlueprintLibrary::UCafeSdkBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::Init(FString ClientId, FString ClientSecret, int32 CafeId)
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartHome()
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartNotice()
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartEvent()
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartMenu()
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartMenuById(int32 MenuId)
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartProfile()
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartWrite(int32 MenuId, FString Subject, FString Text)
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri)
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri)
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartMore()
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartWriteFromScreenshot()
{
    FScreenshotRequest::RequestScreenshot("CafeSdkScreenshot.png", false, false);
}

bool UCafeSdkBlueprintLibrary::IsSupportedOSVersion()
{
    return false;
}

#endif
