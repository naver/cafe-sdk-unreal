// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "AndroidJavaCafeSdk.h"
#include "AndroidJavaGlink.h"
#include "Runtime/Launch/Public/Android/AndroidJNI.h"

FAndroidJavaCafeSdk* GetSharedCafeSdk()
{
    static FAndroidJavaCafeSdk* CafeSdk = nullptr;
    if (CafeSdk == nullptr)
    {
        CafeSdk = new FAndroidJavaCafeSdk();
    }
    return CafeSdk;
}

FAndroidJavaCafeSdk::FAndroidJavaCafeSdk()
    : FJavaClassObject(GetClassName(), "()V")
    , InitMethod(GetClassMethod("init", "(Ljava/lang/String;Ljava/lang/String;I)V"))
{
}

void FAndroidJavaCafeSdk::Init(FString ClientId, FString ClientSecret, int32 CafeId)
{
    CallMethod<void>(InitMethod,
        FJavaClassObject::GetJString(ClientId),
        FJavaClassObject::GetJString(ClientSecret),
        CafeId
        );
}

FName FAndroidJavaCafeSdk::GetClassName()
{
    if (FAndroidMisc::GetAndroidBuildVersion() >= 1)
    {
        return FName("com.naver.cafe.CafeSdk");
    }
    else
    {
        return FName("");
    }
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnSdkStarted(JNIEnv* jenv, jobject thiz)
{
    FCafeSDKPluginModule::OnCafeSdkStarted.Broadcast();
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnSdkStopped(JNIEnv* jenv, jobject thiz)
{
    FCafeSDKPluginModule::OnCafeSdkStopped.Broadcast();
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnClickAppSchemeBanner(JNIEnv* jenv, jobject thiz, jstring AppScheme)
{
    const char* AppSchemeChars = jenv->GetStringUTFChars(AppScheme, 0);
    
    FString appScheme = UTF8_TO_TCHAR(AppSchemeChars);
    FCafeSDKPluginModule::OnCafeSdkClickAppSchemeBanner.Broadcast(appScheme);
    
    jenv->ReleaseStringUTFChars(AppScheme, AppSchemeChars);
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnJoined(JNIEnv* jenv, jobject thiz)
{
    FCafeSDKPluginModule::OnCafeSdkJoined.Broadcast();
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnPostedArticle(JNIEnv* jenv, jobject thiz, jint MenuId, jint ImageCount, jint VideoCount)
{
    FCafeSDKPluginModule::OnCafeSdkPostedArticle.Broadcast(MenuId, ImageCount, VideoCount);
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnPostedComment(JNIEnv* jenv, jobject thiz, jint ArticleId)
{
    FCafeSDKPluginModule::OnCafeSdkPostedComment.Broadcast(ArticleId);
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnVoted(JNIEnv* jenv, jobject thiz, jint ArticleId)
{
    FCafeSDKPluginModule::OnCafeSdkDidVote.Broadcast(ArticleId);
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnWidgetScreenshotClick(JNIEnv* jenv, jobject thiz)
{
    FScreenshotRequest::RequestScreenshot("CafeSdkScreenshot.png", false, false);
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnRecordFinished(JNIEnv* jenv, jobject thiz, jstring FileUrl)
{
    const char* FileUrlChars = jenv->GetStringUTFChars(FileUrl, 0);
    
    FString fileUrl = UTF8_TO_TCHAR(FileUrlChars);
    FCafeSDKPluginModule::OnCafeSdkRecordFinish.Broadcast(fileUrl);
    
    jenv->ReleaseStringUTFChars(FileUrl, FileUrlChars);
}
