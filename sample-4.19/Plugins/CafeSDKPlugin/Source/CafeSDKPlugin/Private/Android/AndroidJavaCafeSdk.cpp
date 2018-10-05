// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "AndroidJavaCafeSdk.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJava.h"
#include "Runtime/Launch/Public/Android/AndroidJNI.h"

FAndroidJavaCafeSdk::FAndroidJavaCafeSdk()
    : FJavaClassObject(GetClassName(), "()V")
    , InitMethod(GetClassMethod("init", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;I)V"))
    , InitGlobalMethod(GetClassMethod("initGlobal", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;I)V"))
    , StartMoreMethod(GetClassMethod("startMore", "(Landroid/app/Activity;)V"))
    , LoginMethod(GetClassMethod("login", "(Landroid/content/Context;)V"))
    , LogoutMethod(GetClassMethod("logout", "(Landroid/content/Context;)V"))
    , IsLoginMethod(GetClassMethod("isLogin", "(Landroid/content/Context;)Z"))
    , GetProfileMethod(GetClassMethod("getProfile", "(Landroid/content/Context;)V"))
    , StartRecordMethod(GetClassMethod("startRecord", "(Landroid/content/Context;)V"))
    , StopRecordMethod(GetClassMethod("stopRecord", "()V"))
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    jclass localGlinkClass = FAndroidApplication::FindJavaClass(GetGlinkClassName().GetPlainANSIString());
    GlinkClass = (jclass)JEnv->NewGlobalRef(localGlinkClass);
    JEnv->DeleteLocalRef(localGlinkClass);

    SetChannelCodeMethod = GetGlinkClassStaticMethod("setChannelCode", "(Ljava/lang/String;)V");
    StartHomeMethod = GetGlinkClassStaticMethod("startHome", "(Landroid/content/Context;)V");
    //StartNoticeMethod = GetGlinkClassStaticMethod("startNotice", "(Landroid/content/Context;)V");
    //StartEventMethod = GetGlinkClassStaticMethod("startEvent", "(Landroid/content/Context;)V");
    //StartMenuMethod = GetGlinkClassStaticMethod("startMenu", "(Landroid/content/Context;)V");
    //StartProfileMethod = GetGlinkClassStaticMethod("startProfile", "(Landroid/content/Context;)V");
    StartWriteMethod = GetGlinkClassStaticMethod("startWrite", "(Landroid/content/Context;)V");
    StartImageWriteMethod = GetGlinkClassStaticMethod("startImageWrite", "(Landroid/content/Context;Ljava/lang/String;)V");
    StartVideoWriteMethod = GetGlinkClassStaticMethod("startVideoWrite", "(Landroid/content/Context;Ljava/lang/String;)V");
    StopMethod = GetGlinkClassStaticMethod("stop", "(Landroid/content/Context;)V");
    IsShowMethod = GetGlinkClassStaticMethod("isShowGlink", "(Landroid/content/Context;)Z");
    SyncGameUserIdMethod = GetGlinkClassStaticMethod("syncGameUserId", "(Landroid/content/Context;Ljava/lang/String;)V");
    StartWidgetMethod = GetGlinkClassStaticMethod("startWidget", "(Landroid/content/Context;)V");
    StopWidgetMethod = GetGlinkClassStaticMethod("stopWidget", "(Landroid/content/Context;)V");
    ShowWidgetWhenUnloadSdkMethod = GetGlinkClassStaticMethod("showWidgetWhenUnloadSdk", "(Landroid/content/Context;Z)V");
    SetWidgetStartPositionMethod = GetGlinkClassStaticMethod("setWidgetStartPosition", "(Landroid/content/Context;ZI)V");
    SetUseVideoRecordMethod = GetGlinkClassStaticMethod("setUseVideoRecord", "(Landroid/content/Context;Z)V");
    SetUseScreenshotMethod = GetGlinkClassStaticMethod("setUseScreenshot", "(Landroid/content/Context;Z)V");
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

void FAndroidJavaCafeSdk::InitGlobal(FString ConsumerKey, FString ConsumerSecret, int32 CommunityId)
{
    CallMethod<void>(InitGlobalMethod,
        FJavaWrapper::GameActivityThis,
        FJavaClassObject::GetJString(ConsumerKey),
        FJavaClassObject::GetJString(ConsumerSecret),
        CommunityId
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

void FAndroidJavaCafeSdk::SetChannelCode(FString ChannelCode) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(GlinkClass, SetChannelCodeMethod.Method, FJavaClassObject::GetJString(ChannelCode));
}

void FAndroidJavaCafeSdk::StartHome() const
{
    StartTab(StartHomeMethod);
}

void FAndroidJavaCafeSdk::StartNotice() const
{
  //StartTab(StartNoticeMethod);
}

void FAndroidJavaCafeSdk::StartEvent() const
{
  //StartTab(StartEventMethod);
}

void FAndroidJavaCafeSdk::StartMenu() const
{
  //StartTab(StartMenuMethod);
}

void FAndroidJavaCafeSdk::StartProfile() const
{
  //StartTab(StartProfileMethod);
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

void FAndroidJavaCafeSdk::Stop() const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(GlinkClass, StopMethod.Method, FJavaWrapper::GameActivityThis);
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

void FAndroidJavaCafeSdk::SetUseScreenShot(bool bUse) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(GlinkClass, SetUseScreenshotMethod.Method, FJavaWrapper::GameActivityThis, bUse);
}

bool FAndroidJavaCafeSdk::IsSupportedOSVersion() const
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

void FAndroidJavaCafeSdk::InitRecord()
{
    // do nothing.
}

void FAndroidJavaCafeSdk::StartRecord()
{
    CallMethod<void>(StartRecordMethod, FJavaWrapper::GameActivityThis);
}

void FAndroidJavaCafeSdk::StopRecord()
{
    CallMethod<void>(StopRecordMethod);
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

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnStartRecord(JNIEnv* jenv, jobject thiz)
{
    FCafeSDKPluginModule::OnStartRecord.Broadcast();
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnErrorRecord(JNIEnv* jenv, jobject thiz)
{
    FCafeSDKPluginModule::OnErrorRecord.Broadcast(UTF8_TO_TCHAR(""));
}

extern "C" void Java_com_naver_cafe_CafeSdk_nativeOnFinishRecord(JNIEnv* jenv, jobject thiz, jstring FileUrl)
{
    const char* FileUrlChars = jenv->GetStringUTFChars(FileUrl, 0);
    
    FString fileUrl = UTF8_TO_TCHAR(FileUrlChars);
    FCafeSDKPluginModule::OnFinishRecord.Broadcast(fileUrl);
    
    jenv->ReleaseStringUTFChars(FileUrl, FileUrlChars);
}
