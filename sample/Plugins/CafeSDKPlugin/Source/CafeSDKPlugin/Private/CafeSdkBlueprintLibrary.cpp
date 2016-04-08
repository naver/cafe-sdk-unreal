// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "CafeSdkBlueprintLibrary.h"

#if PLATFORM_ANDROID

#include "AndroidJavaGlink.h"
#include "AndroidJavaCafeSdk.h"

UCafeSdkBlueprintLibrary::UCafeSdkBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    // do nothing.
}

void UCafeSdkBlueprintLibrary::StartHome()
{
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    
    FAndroidJavaGlink Glink;
    Glink.StartHome();
}

void UCafeSdkBlueprintLibrary::StartNotice()
{
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    
    FAndroidJavaGlink Glink;
    Glink.StartNotice();
}

void UCafeSdkBlueprintLibrary::StartEvent()
{
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    
    FAndroidJavaGlink Glink;
    Glink.StartEvent();
}

void UCafeSdkBlueprintLibrary::StartMenu()
{
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    
    FAndroidJavaGlink Glink;
    Glink.StartMenu();
}

void UCafeSdkBlueprintLibrary::StartMenuById(int32 MenuId)
{
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    
    FAndroidJavaGlink Glink;
    Glink.StartMenuById(MenuId);
}

void UCafeSdkBlueprintLibrary::StartProfile()
{
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    
    FAndroidJavaGlink Glink;
    Glink.StartProfile();
}

void UCafeSdkBlueprintLibrary::StartWrite(int32 MenuId, FString Subject, FString Text)
{
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    
    FAndroidJavaGlink Glink;
    Glink.StartWrite(MenuId, Subject, Text);
}

void UCafeSdkBlueprintLibrary::StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri)
{
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    
    FAndroidJavaGlink Glink;
    Glink.StartImageWrite(MenuId, Subject, Text, ImageUri);
}

void UCafeSdkBlueprintLibrary::StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri)
{
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    
    FAndroidJavaGlink Glink;
    Glink.StartVideoWrite(MenuId, Subject, Text, VideoUri);
}

#else

UCafeSdkBlueprintLibrary::UCafeSdkBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
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
