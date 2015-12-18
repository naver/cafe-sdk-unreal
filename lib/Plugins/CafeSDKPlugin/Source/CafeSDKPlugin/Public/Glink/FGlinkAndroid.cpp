#include "CafeSDKPluginPrivatePCH.h"
#include "FGlink.h"




#if PLATFORM_ANDROID

#include "FGlinkAndroid.h"
#include "Runtime/Core/Private/CorePrivatePCH.h"
#include "Android/AndroidMisc.h"



FGlinkAndroid::FGlinkAndroid()
: FGlink()
, FJavaClassObject(GetClassName(), "()V")
, initMethod(GetClassMethod("init", "(Ljava/lang/String;Ljava/lang/String;I)V"))
, executeMainMethod(GetClassMethod("startHome", "(Landroid/app/Activity;)V"))
//, executeArticlePostMethod(GetClassMethod("startWrite", "(Landroid/app/Activity;I;Ljava/lang/String;Ljava/lang/String)V"))
//, executeArticlePostWithImageMethod(GetClassMethod("startImageWrite", "(Landroid/app/Activity;I;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String)V"))
//, executeArticlePostWithVideoMethod(GetClassMethod("startVideoWrite", "(Landroid/app/Activity;I;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String)V"))
{
    
    CallMethod<void>(initMethod, GetJString(FGlinkAndroid::NaverLoginClientId), GetJString(FGlinkAndroid::NaverLoginClientSecret), FGlinkAndroid::CafeId);
}


void FGlinkAndroid::executeMain()
{
    CallMethod<void>(executeMainMethod, FJavaWrapper::GameActivityThis);
}

//void FGlinkAndroid::executeArticlePost(int menuId, FString subject, FString content) {
//    CallMethod<void>(executeArticlePostMethod, FJavaWrapper::GameActivityThis, menuId, GetJString(subject), GetJString(content));
//}
//
//void FGlinkAndroid::executeArticlePostWithImage(int menuId, FString subject, FString content, FString filePath) {
//    CallMethod<void>(executeArticlePostWithImageMethod, FJavaWrapper::GameActivityThis, GetJString(subject), GetJString(content), GetJString(filePath));
//}
//
//void FGlinkAndroid::executeArticlePostWithVideo(int menuId, FString subject, FString content, FString filePath) {
//    CallMethod<void>(executeArticlePostWithVideoMethod, FJavaWrapper::GameActivityThis, GetJString(subject), GetJString(content), GetJString(filePath));
//}

FName FGlinkAndroid::GetClassName()
{
    
    if (FAndroidMisc::GetAndroidBuildVersion() >= 1)
    {
        return FName("cafesdk/CafeSdk");
    }
    else
    {
        return FName("");
    }
}


#endif
