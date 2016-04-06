#include "CafeSDKPluginPrivatePCH.h"
#include "AndroidJavaCafeSdk.h"

#if PLATFORM_ANDROID

#include "Runtime/Launch/Public/Android/AndroidJNI.h"

FAndroidJavaCafeSdk::FAndroidJavaCafeSdk()
    : FJavaClassObject(GetClassName(), "()V")
    , InitMethod(GetClassMethod("init", "()V"))
    , ShowMessageMethod(GetClassMethod("showMessage", "(Landroid/app/Activity;)V"))
{
    CallMethod<void>(InitMethod);
}

void FAndroidJavaCafeSdk::ShowMessage()
{
    CallMethod<void>(ShowMessageMethod, FJavaWrapper::GameActivityThis);
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
    FJavaAndroidMessageBox MessageBox;
    MessageBox.SetText(message);
    MessageBox.AddButton("ok");
    MessageBox.Show();
}

extern "C" void Java_cafesdk_CafeSdk_nativeShowMessageBox(JNIEnv* jenv, jobject thiz)
{
    ShowMessage("show message box.");
}

extern "C" void Java_cafesdk_CafeSdk_nativeOnSdkStarted(JNIEnv* jenv, jobject thiz)
{
    if (FTaskGraphInterface::IsRunning())
    {
        FEvent* Event = FPlatformProcess::GetSynchEventFromPool();
        
        FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([&]()
        {
            ShowMessage("cafe sdk started.");
        }, TStatId(), NULL, ENamedThreads::MainQueue);
        
        FTaskGraphInterface::Get().TriggerEventWhenTaskCompletes(Event, Task, ENamedThreads::GameThread);
    }
}

#endif // PLATFORM_ANDROID
