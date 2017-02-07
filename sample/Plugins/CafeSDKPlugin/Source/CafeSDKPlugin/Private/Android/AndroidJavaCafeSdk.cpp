// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "AndroidJavaCafeSdk.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJava.h"
#include "Runtime/Launch/Public/Android/AndroidJNI.h"

FAndroidJavaCafeSdk::FAndroidJavaCafeSdk()
    : FJavaClassObject(GetClassName(), "()V")
    , InitMethod(GetClassMethod("init", "(Landroid/app/Activity;Ljava/lang/String;Ljava/lang/String;I)V"))
    , InitGlobalMethod(GetClassMethod("initGlobal", "(Landroid/app/Activity;Ljava/lang/String;I)V"))
    , StartMoreMethod(GetClassMethod("startMore", "(Landroid/app/Activity;)V"))
    , LoginMethod(GetClassMethod("login", "(Landroid/app/Activity;)V"))
    , LogoutMethod(GetClassMethod("logout", "(Landroid/app/Activity;)V"))
    , IsLoginMethod(GetClassMethod("isLogin", "(Landroid/app/Activity;)Z"))
    , GetProfileMethod(GetClassMethod("getProfile", "(Landroid/app/Activity;)V"))
{
    GlinkClass = FAndroidApplication::FindJavaClass(GetGlinkClassName().GetPlainANSIString());
    StartHomeMethod = GetGlinkClassStaticMethod("startHome", "(Landroid/app/Activity;)V");
    StartNoticeMethod = GetGlinkClassStaticMethod("startNotice", "(Landroid/app/Activity;)V");
    StartEventMethod = GetGlinkClassStaticMethod("startEvent", "(Landroid/app/Activity;)V");
    StartMenuMethod = GetGlinkClassStaticMethod("startMenu", "(Landroid/app/Activity;)V");
    StartProfileMethod = GetGlinkClassStaticMethod("startProfile", "(Landroid/app/Activity;)V");
    StartWriteMethod = GetGlinkClassStaticMethod("startWrite", "(Landroid/app/Activity;)V");
    StartImageWriteMethod = GetGlinkClassStaticMethod("startImageWrite", "(Landroid/app/Activity;Ljava/lang/String;)V");
    StartVideoWriteMethod = GetGlinkClassStaticMethod("startVideoWrite", "(Landroid/app/Activity;Ljava/lang/String;)V");
    IsShowMethod = GetGlinkClassStaticMethod("isShowGlink", "(Landroid/app/Activity;)Z");
    SyncGameUserIdMethod = GetGlinkClassStaticMethod("syncGameUserId", "(Landroid/app/Activity;Ljava/lang/String;)V");
    StartWidgetMethod = GetGlinkClassStaticMethod("startWidget", "(Landroid/app/Activity;)V");
    StopWidgetMethod = GetGlinkClassStaticMethod("stopWidget", "(Landroid/app/Activity;)V");
    ShowWidgetWhenUnloadSdkMethod = GetGlinkClassStaticMethod("showWidgetWhenUnloadSdk", "(Landroid/app/Activity;Z)V");
    SetWidgetStartPositionMethod = GetGlinkClassStaticMethod("setWidgetStartPosition", "(Landroid/app/Activity;ZI)V");
    SetUseVideoRecordMethod = GetGlinkClassStaticMethod("setUseVideoRecord", "(Landroid/app/Activity;Z)V");
    SetThemeColorMethod = GetGlinkClassStaticMethod("setThemeColor", "(Ljava/lang/String;Ljava/lang/String;)V");
    GetAndroidVersionMethod = GetGlinkClassStaticMethod("getAndroidVersion", "()I");
    
    StatisticsClass = FAndroidApplication::FindJavaClass(GetStatisticsClassName().GetPlainANSIString());
    SendNewUserMethod = GetStatisticsClassStaticMethod("sendNewUser", "(Ljava/lang/String;Ljava/lang/String;)V");
    SendPayUserMethod = GetStatisticsClassStaticMethod("sendPayUser", "(Ljava/lang/String;DLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
}

void FAndroidJavaCafeSdk::Init(FString ClientId, FString ClientSecret, int32 CafeId)
{
    CallMethod<void>(InitMethod,
        FJavaWrapper::GameActivityThis,
        FJavaClassObject::GetJString(ClientId),
        FJavaClassObject::GetJString(ClientSecret),
        CafeId
        );
}

void FAndroidJavaCafeSdk::InitGlobal(FString ClientId, int32 CafeId)
{
    CallMethod<void>(InitGlobalMethod,
        FJavaWrapper::GameActivityThis,
        FJavaClassObject::GetJString(ClientId),
        CafeId
        );
}

void FAndroidJavaCafeSdk::StartMore()
{
    CallMethod<void>(StartMoreMethod,
        FJavaWrapper::GameActivityThis
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

void FAndroidJavaCafeSdk::StartHome() const
{
    StartTab(StartHomeMethod);
}

void FAndroidJavaCafeSdk::StartNotice() const
{
    StartTab(StartNoticeMethod);
}

void FAndroidJavaCafeSdk::StartEvent() const
{
    StartTab(StartEventMethod);
}

void FAndroidJavaCafeSdk::StartMenu() const
{
    StartTab(StartMenuMethod);
}

void FAndroidJavaCafeSdk::StartProfile() const
{
    StartTab(StartProfileMethod);
}

void FAndroidJavaCafeSdk::StartTab(const FJavaClassMethod& JavaClassMethod) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(GlinkClass, JavaClassMethod.Method, FJavaWrapper::GameActivityThis);
}

void FAndroidJavaCafeSdk::StartWrite() const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(GlinkClass,
                               StartWriteMethod.Method,
                               FJavaWrapper::GameActivityThis
                               );
}

void FAndroidJavaCafeSdk::StartImageWrite(FString ImageUri) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(GlinkClass,
                               StartImageWriteMethod.Method,
                               FJavaWrapper::GameActivityThis,
                               FJavaClassObject::GetJString(ImageUri)
                               );
}

void FAndroidJavaCafeSdk::StartVideoWrite(FString VideoUri) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(GlinkClass,
                               StartVideoWriteMethod.Method,
                               FJavaWrapper::GameActivityThis,
                               FJavaClassObject::GetJString(VideoUri)
                               );
}

void FAndroidJavaCafeSdk::SetThemeColor(FString ThemeColorCSSString, FString TabBackgroundColorCSSString) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(GlinkClass,
                               SetThemeColorMethod.Method,
                               FJavaClassObject::GetJString(ThemeColorCSSString),
                               FJavaClassObject::GetJString(TabBackgroundColorCSSString)
                               );
}

bool FAndroidJavaCafeSdk::IsShow() const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    return JEnv->CallStaticBooleanMethod(GlinkClass, IsShowMethod.Method, FJavaWrapper::GameActivityThis);
}

void FAndroidJavaCafeSdk::SyncGameUserId(FString GameUserId) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(GlinkClass, SyncGameUserIdMethod.Method, FJavaWrapper::GameActivityThis, FJavaClassObject::GetJString(GameUserId));
}

void FAndroidJavaCafeSdk::StartWidget() const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(GlinkClass,
                               StartWidgetMethod.Method,
                               FJavaWrapper::GameActivityThis);
}

void FAndroidJavaCafeSdk::StopWidget() const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(GlinkClass, StopWidgetMethod.Method, FJavaWrapper::GameActivityThis);
}

void FAndroidJavaCafeSdk::ShowWidgetWhenUnloadSdk(bool bUse) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(GlinkClass,
                               ShowWidgetWhenUnloadSdkMethod.Method,
                               FJavaWrapper::GameActivityThis, bUse);
}

void FAndroidJavaCafeSdk::SetWidgetStartPosition(bool bIsLeft, int32 HeightPercentage) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(GlinkClass,
                               SetWidgetStartPositionMethod.Method,
                               FJavaWrapper::GameActivityThis,
                               bIsLeft,
                               HeightPercentage);
}

void FAndroidJavaCafeSdk::SetUseVideoRecord(bool bUse) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(GlinkClass, SetUseVideoRecordMethod.Method, FJavaWrapper::GameActivityThis, bUse);
}

bool FAndroidJavaCafeSdk::IsSupportedAndroidVersion() const
{
    static const int kSupportedMinVersion = 17; // kitkat.
    
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    int version = JEnv->CallStaticIntMethod(GlinkClass, GetAndroidVersionMethod.Method);
    return version > kSupportedMinVersion;
}

FJavaClassMethod FAndroidJavaCafeSdk::GetGlinkClassStaticMethod(const char* MethodName, const char* FuncSig) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    FJavaClassMethod Method;
    Method.Method = JEnv->GetStaticMethodID(GlinkClass, MethodName, FuncSig);
    Method.Name = MethodName;
    Method.Signature = FuncSig;
    // Is method valid?
    checkf(Method.Method, TEXT("Unable to find Java Method %s with Signature %s"), UTF8_TO_TCHAR(MethodName), UTF8_TO_TCHAR(FuncSig));
    return Method;
}

FName FAndroidJavaCafeSdk::GetGlinkClassName()
{
    if (FAndroidMisc::GetAndroidBuildVersion() >= 1)
    {
        return FName("com.naver.glink.android.sdk.Glink");
    }
    else
    {
        return FName("");
    }
}

void FAndroidJavaCafeSdk::SendNewUser(FString GameUserId, FString Market)
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(StatisticsClass,
                               SendNewUserMethod.Method,
                               FJavaClassObject::GetJString(GameUserId),
                               FJavaClassObject::GetJString(Market)
                               );
}

void FAndroidJavaCafeSdk::SendPayUser(FString GameUserId, double Pay, FString ProductCode, FString Currency, FString Market)
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(StatisticsClass,
                               SendPayUserMethod.Method,
                               FJavaClassObject::GetJString(GameUserId),
                               Pay,
                               FJavaClassObject::GetJString(ProductCode),
                               FJavaClassObject::GetJString(Currency),
                               FJavaClassObject::GetJString(Market)
                               );
}

FJavaClassMethod FAndroidJavaCafeSdk::GetStatisticsClassStaticMethod(const char* MethodName, const char* FuncSig) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    FJavaClassMethod Method;
    Method.Method = JEnv->GetStaticMethodID(StatisticsClass, MethodName, FuncSig);
    Method.Name = MethodName;
    Method.Signature = FuncSig;
    // Is method valid?
    checkf(Method.Method, TEXT("Unable to find Java Method %s with Signature %s"), UTF8_TO_TCHAR(MethodName), UTF8_TO_TCHAR(FuncSig));
    return Method;
}

FName FAndroidJavaCafeSdk::GetStatisticsClassName()
{
    if (FAndroidMisc::GetAndroidBuildVersion() >= 1)
    {
        return FName("com.naver.glink.android.sdk.Statistics");
    }
    else
    {
        return FName("");
    }
}

void FAndroidJavaCafeSdk::Init(FString ClientId, FString ClientSecret)
{
    Init(ClientId, ClientSecret, -1);
}

void FAndroidJavaCafeSdk::Login()
{
    CallMethod<void>(LoginMethod, FJavaWrapper::GameActivityThis);
}

void FAndroidJavaCafeSdk::Logout()
{
    CallMethod<void>(LogoutMethod, FJavaWrapper::GameActivityThis);
}

bool FAndroidJavaCafeSdk::IsLogin()
{
    return CallMethod<bool>(IsLoginMethod, FJavaWrapper::GameActivityThis);
}

void FAndroidJavaCafeSdk::GetProfile()
{
    CallMethod<void>(GetProfileMethod, FJavaWrapper::GameActivityThis);
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

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnLoggedIn(JNIEnv* jenv, jobject thiz, jboolean bSuccss)
{
    FCafeSDKPluginModule::OnLoggedIn.Broadcast(bSuccss);
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnGetProfile(JNIEnv* jenv, jobject thiz, jstring JsonString)
{
    const char* JsonStringChars = jenv->GetStringUTFChars(JsonString, 0);
    
    FString jsonString = UTF8_TO_TCHAR(JsonStringChars);
    FCafeSDKPluginModule::OnGetProfile.Broadcast(jsonString);
    
    jenv->ReleaseStringUTFChars(JsonString, JsonStringChars);
}
