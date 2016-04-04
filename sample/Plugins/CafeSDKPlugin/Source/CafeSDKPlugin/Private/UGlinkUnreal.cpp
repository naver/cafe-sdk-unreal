#include "CafeSDKPluginPrivatePCH.h"
#include "UGlinkUnreal.h"
#include "AndroidJavaGlink.h"


#if PLATFORM_ANDROID

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

void UGlinkUnreal::executeMain()
{
    FAndroidJavaGlink Glink;
    Glink.StartHome();
}

void UGlinkUnreal::executeArticlePost(int32 menuId, FString subject, FString content) {
}

void UGlinkUnreal::executeArticlePostWithImage(int32 menuId, FString subject, FString content, FString filePath) {
}

void UGlinkUnreal::executeArticlePostWithVideo(int32 menuId, FString subject, FString content, FString filePath) {
}

#endif