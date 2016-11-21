// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "AndroidJavaGlink.h"

FAndroidJavaGlink* GetSharedGlink()
{
    static FAndroidJavaGlink* Glink = nullptr;
    if (Glink == nullptr)
    {
        Glink = new FAndroidJavaGlink();
    }
    return Glink;
}

FAndroidJavaGlink::FAndroidJavaGlink()
{
    Class = FAndroidApplication::FindJavaClass(GetClassName().GetPlainANSIString());
    
    StartHomeMethod = GetClassStaticMethod("startHome", "(Landroid/app/Activity;)V");
    StartNoticeMethod = GetClassStaticMethod("startNotice", "(Landroid/app/Activity;)V");
    StartEventMethod = GetClassStaticMethod("startEvent", "(Landroid/app/Activity;)V");
    StartMenuMethod = GetClassStaticMethod("startMenu", "(Landroid/app/Activity;)V");
    StartMenuByIdMethod = GetClassStaticMethod("startMenu", "(Landroid/app/Activity;I)V");
    StartProfileMethod = GetClassStaticMethod("startProfile", "(Landroid/app/Activity;)V");
    StartWriteMethod = GetClassStaticMethod("startWrite", "(Landroid/app/Activity;ILjava/lang/String;Ljava/lang/String;)V");
    StartImageWriteMethod = GetClassStaticMethod("startImageWrite", "(Landroid/app/Activity;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    StartVideoWriteMethod = GetClassStaticMethod("startVideoWrite", "(Landroid/app/Activity;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    
    IsShowMethod = GetClassStaticMethod("isShowGlink", "(Landroid/app/Activity;)Z");
    SyncGameUserIdMethod = GetClassStaticMethod("syncGameUserId", "(Landroid/app/Activity;Ljava/lang/String;)V");
    
    ShowWidgetWhenUnloadSdkMethod = GetClassStaticMethod("showWidgetWhenUnloadSdk", "(Landroid/app/Activity;Z)V");
    StopWidgetMethod = GetClassStaticMethod("stopWidget", "(Landroid/app/Activity;)V");
    SetUseVideoRecordMethod = GetClassStaticMethod("setUseVideoRecord", "(Landroid/app/Activity;Z)V");
    SetThemeColorMethod = GetClassStaticMethod("setThemeColor", "(Ljava/lang/String;Ljava/lang/String;)V");
    SetXButtonTypeCloseMethod = GetClassStaticMethod("setXButtonTypeClose", "(Landroid/app/Activity;Z)V");
    
    GetAndroidVersionMethod = GetClassStaticMethod("getAndroidVersion", "()I");
    StartMoreMethod = GetClassStaticMethod("startMore", "(Landroid/app/Activity;)V");
}

void FAndroidJavaGlink::StartHome() const
{
    StartTab(StartHomeMethod);
}

void FAndroidJavaGlink::StartNotice() const
{
    StartTab(StartNoticeMethod);
}

void FAndroidJavaGlink::StartEvent() const
{
    StartTab(StartEventMethod);
}

void FAndroidJavaGlink::StartMenu() const
{
    StartTab(StartMenuMethod);
}

void FAndroidJavaGlink::StartMenuById(int32 MenuId) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(Class, StartMenuByIdMethod.Method, FJavaWrapper::GameActivityThis, MenuId);
}

void FAndroidJavaGlink::StartProfile() const
{
    StartTab(StartProfileMethod);
}

void FAndroidJavaGlink::StartTab(const FJavaClassMethod& JavaClassMethod) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(Class, JavaClassMethod.Method, FJavaWrapper::GameActivityThis);
}

void FAndroidJavaGlink::StartWrite(int32 MenuId, FString Subject, FString Text) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(Class,
        StartWriteMethod.Method,
        FJavaWrapper::GameActivityThis,
        MenuId,
        FJavaClassObject::GetJString(Subject),
        FJavaClassObject::GetJString(Text)
        );
}

void FAndroidJavaGlink::StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(Class,
        StartImageWriteMethod.Method,
        FJavaWrapper::GameActivityThis,
        MenuId,
        FJavaClassObject::GetJString(Subject),
        FJavaClassObject::GetJString(Text),
        FJavaClassObject::GetJString(ImageUri)
        );
}

void FAndroidJavaGlink::StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(Class,
        StartVideoWriteMethod.Method,
        FJavaWrapper::GameActivityThis,
        MenuId,
        FJavaClassObject::GetJString(Subject),
        FJavaClassObject::GetJString(Text),
        FJavaClassObject::GetJString(VideoUri)
        );
}

void FAndroidJavaGlink::SetThemeColor(FString ThemeColorCSSString, FString TabBackgroundColorCSSString) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(Class,
        SetThemeColorMethod.Method,
        FJavaClassObject::GetJString(ThemeColorCSSString),
        FJavaClassObject::GetJString(TabBackgroundColorCSSString)
        );
}

void FAndroidJavaGlink::SetXButtonTypeClose(bool bUse) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(Class, SetXButtonTypeCloseMethod.Method, FJavaWrapper::GameActivityThis, bUse);
}

bool FAndroidJavaGlink::IsShow() const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    return JEnv->CallStaticBooleanMethod(Class, IsShowMethod.Method, FJavaWrapper::GameActivityThis);
}

void FAndroidJavaGlink::SyncGameUserId(FString GameUserId) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(Class, SyncGameUserIdMethod.Method, FJavaWrapper::GameActivityThis, FJavaClassObject::GetJString(GameUserId));
}

void FAndroidJavaGlink::ShowWidgetWhenUnloadSdk(bool bUse) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(Class, ShowWidgetWhenUnloadSdkMethod.Method, FJavaWrapper::GameActivityThis, bUse);
}

void FAndroidJavaGlink::StopWidget() const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(Class, StopWidgetMethod.Method, FJavaWrapper::GameActivityThis);
}

void FAndroidJavaGlink::SetUseVideoRecord(bool bUse) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    JEnv->CallStaticVoidMethod(Class, SetUseVideoRecordMethod.Method, FJavaWrapper::GameActivityThis, bUse);
}

void FAndroidJavaGlink::StartMore() const
{
    StartTab(StartMoreMethod);
}

bool FAndroidJavaGlink::IsSupportedAndroidVersion() const
{
    static const int kSupportedMinVersion = 17; // kitkat.
    
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    int version = JEnv->CallStaticIntMethod(Class, GetAndroidVersionMethod.Method);
    return version > kSupportedMinVersion;
}

FJavaClassMethod FAndroidJavaGlink::GetClassStaticMethod(const char* MethodName, const char* FuncSig) const
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    FJavaClassMethod Method;
    Method.Method = JEnv->GetStaticMethodID(Class, MethodName, FuncSig);
    Method.Name = MethodName;
    Method.Signature = FuncSig;
    // Is method valid?
    checkf(Method.Method, TEXT("Unable to find Java Method %s with Signature %s"), UTF8_TO_TCHAR(MethodName), UTF8_TO_TCHAR(FuncSig));
    return Method;
}

FName FAndroidJavaGlink::GetClassName()
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
