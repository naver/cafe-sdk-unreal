#include "CafeSDKPluginPrivatePCH.h"
#include "UGlinkUnreal.h"


#if PLATFORM_ANDROID

#include "AndroidJavaGlink.h"
#include "AndroidJavaCafeSdk.h"


UGlinkUnreal::UGlinkUnreal( const FObjectInitializer& ObjectInitializer )
    : Super( ObjectInitializer )
{
    FAndroidJavaGlink Glink;
    Glink.Init("197CymaStozo7X5r2qR5", "evCgKH1kJL", 28290504);
}

void UGlinkUnreal::StartProfile()
{
    FAndroidJavaGlink Glink;
    Glink.StartProfile();
}

void UGlinkUnreal::StartHome()
{
    FAndroidJavaGlink Glink;
    Glink.StartHome();
}

void UGlinkUnreal::StartNotice()
{
    FAndroidJavaGlink Glink;
    Glink.StartNotice();
}

void UGlinkUnreal::StartEvent()
{
//    FAndroidJavaGlink Glink;
//    Glink.StartEvent();
    
    FAndroidJavaCafeSdk CafeSdk;
    CafeSdk.ShowMessage();
}

#else

UGlinkUnreal::UGlinkUnreal( const FObjectInitializer& ObjectInitializer )
    : Super( ObjectInitializer )
{
    // do nothing.
}

void UGlinkUnreal::StartProfile()
{
    // do nothing.
}

void UGlinkUnreal::StartHome()
{
    // do nothing.
}

void UGlinkUnreal::StartNotice()
{
    // do nothing.
}

void UGlinkUnreal::StartEvent()
{
    // do nothing.
}

#endif
