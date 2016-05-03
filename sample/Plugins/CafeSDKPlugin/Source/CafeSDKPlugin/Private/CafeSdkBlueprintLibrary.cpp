// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "CafeSdkBlueprintLibrary.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJavaGlink.h"
#include "Android/AndroidJavaCafeSdk.h"

FAndroidJavaGlink* GetSharedGlink()
{
    static FAndroidJavaGlink* Glink = nullptr;
    if (Glink == nullptr)
    {
        Glink = new FAndroidJavaGlink();
    }
    return Glink;
}

FAndroidJavaCafeSdk* GetSharedCafeSdk()
{
    static FAndroidJavaCafeSdk* CafeSdk = nullptr;
    if (CafeSdk == nullptr)
    {
        CafeSdk = new FAndroidJavaCafeSdk();
    }
    return CafeSdk;
}

UCafeSdkBlueprintLibrary::UCafeSdkBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::Init(FString ClientId, FString ClientSecret, int32 CafeId)
{
    GetSharedCafeSdk()->Init(ClientId, ClientSecret, CafeId);
}

void UCafeSdkBlueprintLibrary::StartHome()
{
    GetSharedGlink()->StartHome();
}

void UCafeSdkBlueprintLibrary::StartNotice()
{
    GetSharedGlink()->StartNotice();
}

void UCafeSdkBlueprintLibrary::StartEvent()
{
    GetSharedGlink()->StartEvent();
}

void UCafeSdkBlueprintLibrary::StartMenu()
{
    GetSharedGlink()->StartMenu();
}

void UCafeSdkBlueprintLibrary::StartMenuById(int32 MenuId)
{
    GetSharedGlink()->StartMenuById(MenuId);
}

void UCafeSdkBlueprintLibrary::StartProfile()
{
    GetSharedGlink()->StartProfile();
}

void UCafeSdkBlueprintLibrary::StartWrite(int32 MenuId, FString Subject, FString Text)
{
    GetSharedGlink()->StartWrite(MenuId, Subject, Text);
}

void UCafeSdkBlueprintLibrary::StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri)
{
    GetSharedGlink()->StartImageWrite(MenuId, Subject, Text, ImageUri);
}

void UCafeSdkBlueprintLibrary::StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri)
{
    GetSharedGlink()->StartVideoWrite(MenuId, Subject, Text, VideoUri);
}

#elif PLATFORM_IOS

#import <NaverCafeSDK/NCSDKManager.h>
#import <NaverCafeSDK/NCSDKLoginManager.h>
#include "IOSAppDelegate.h"

static void ListenNCSDKOpenURL(UIApplication* application, NSURL* url, NSString* sourceApplication, id annotation)
{
    [[NCSDKLoginManager getSharedInstance] finishNaverLoginWithURL:url];
}

UCafeSdkBlueprintLibrary::UCafeSdkBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

void UCafeSdkBlueprintLibrary::Init(FString ClientId, FString ClientSecret, int32 CafeId)
{
    [[NCSDKManager getSharedInstance] setNaverLoginClientId:ClientId.GetNSString()
                                     naverLoginClientSecret:ClientSecret.GetNSString()
                                                     cafeId:CafeId];
	FIOSCoreDelegates::OnOpenURL.AddStatic(&ListenNCSDKOpenURL);
}

void UCafeSdkBlueprintLibrary::StartHome()
{
    dispatch_sync(dispatch_get_main_queue(), ^{
        [[NCSDKManager getSharedInstance] setParentViewController:[IOSAppDelegate GetDelegate].IOSController];
        [[NCSDKManager getSharedInstance] presentMainViewController];
    });
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

#endif
