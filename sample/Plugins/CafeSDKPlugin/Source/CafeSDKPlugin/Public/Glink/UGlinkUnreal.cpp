#include "CafeSDKPluginPrivatePCH.h"
#include "UGlinkUnreal.h"
#include "FGlinkAndroid.h"



UGlinkUnreal::UGlinkUnreal( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
    glink = NULL;
#if PLATFORM_ANDROID
    glink = new FGlinkAndroid();
#endif
}

void UGlinkUnreal::executeMain() {
    if(glink != NULL ) {
        glink->executeMain();
    }
}

void UGlinkUnreal::executeArticlePost(int32 menuId, FString subject, FString content) {
    if(glink != NULL ) {
        glink->executeArticlePost(menuId, subject, content);
    }
}

void UGlinkUnreal::executeArticlePostWithImage(int32 menuId, FString subject, FString content, FString filePath) {
    if(glink != NULL ) {
        glink->executeArticlePostWithImage(menuId, subject, content, filePath);
    }
}

void UGlinkUnreal::executeArticlePostWithVideo(int32 menuId, FString subject, FString content, FString filePath) {
    if(glink != NULL ) {
        glink->executeArticlePostWithVideo(menuId, subject, content, filePath);
    }
}

