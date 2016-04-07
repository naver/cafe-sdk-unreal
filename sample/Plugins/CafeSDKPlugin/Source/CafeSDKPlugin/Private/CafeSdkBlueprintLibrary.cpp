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

void UCafeSdkBlueprintLibrary::StartProfile()
{
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
    
    FAndroidJavaGlink Glink;
    Glink.StartProfile();
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

void UCafeSdkBlueprintLibrary::StartProfile()
{
    // do nothing.
}

#endif
