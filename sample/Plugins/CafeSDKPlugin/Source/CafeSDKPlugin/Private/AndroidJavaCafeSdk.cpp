#include "CafeSDKPluginPrivatePCH.h"
#include "AndroidJavaCafeSdk.h"

#if PLATFORM_ANDROID

#include "Runtime/Launch/Public/Android/AndroidJNI.h"

FAndroidJavaCafeSdk::FAndroidJavaCafeSdk()
    : FJavaClassObject(GetClassName(), "()V")
    , InitMethod(GetClassMethod("init", "(Ljava/lang/String;Ljava/lang/String;I)V"))
{
}

void FAndroidJavaCafeSdk::Init(FString ClientId, FString ClientSecret, int32 CafeId) const
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
        return FName("cafesdk.CafeSdk");
    }
    else
    {
        return FName("");
    }
}

#include "Android/AndroidJavaMessageBox.h"

static void ShowMessage(const FString& message)
{
    if (FTaskGraphInterface::IsRunning())
    {
        FEvent* Event = FPlatformProcess::GetSynchEventFromPool();
        
        FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
        {
            FJavaAndroidMessageBox MessageBox;
            MessageBox.SetText(message);
            MessageBox.AddButton("ok");
            MessageBox.Show();
        }, TStatId(), NULL, ENamedThreads::GameThread);
        
        FTaskGraphInterface::Get().TriggerEventWhenTaskCompletes(Event, Task, ENamedThreads::GameThread);
    }
}

extern "C" void Java_cafesdk_CafeSdk_nativeOnSdkStarted(JNIEnv* jenv, jobject thiz)
{
    ShowMessage("nativeOnSdkStarted");
}

extern "C" void Java_cafesdk_CafeSdk_nativeOnSdkStopped(JNIEnv* env, jobject thiz)
{
    ShowMessage("nativeOnSdkStopped");
}

extern "C" void Java_cafesdk_CafeSdk_nativeOnClickAppSchemeBanner(JNIEnv* env, jobject thiz, jstring appScheme)
{
    ShowMessage("nativeOnClickAppSchemeBanner");
}

extern "C" void Java_cafesdk_CafeSdk_nativeOnJoined(JNIEnv* env, jobject thiz)
{
    ShowMessage("nativeOnJoined");
}

extern "C" void Java_cafesdk_CafeSdk_nativeOnPostedArticle(JNIEnv* env, jobject thiz, jint menuId)
{
    ShowMessage("nativeOnPostedArticle");
}

extern "C" void Java_cafesdk_CafeSdk_nativeOnPostedComment(JNIEnv* env, jobject thiz, jint articleId)
{
    ShowMessage("nativeOnPostedComment");
}

#endif // PLATFORM_ANDROID
