// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "AndroidJavaCafeSdkStatistics.h"

FAndroidJavaCafeSdkStatistics* GetSharedCafeSdkStatistics()
{
    static FAndroidJavaCafeSdkStatistics* CafeSdkStatistics = nullptr;
    if (CafeSdkStatistics == nullptr)
    {
        CafeSdkStatistics = new FAndroidJavaCafeSdkStatistics();
    }
    return CafeSdkStatistics;
}

FAndroidJavaCafeSdkStatistics::FAndroidJavaCafeSdkStatistics()
{
    Class = FAndroidApplication::FindJavaClass(GetClassName().GetPlainANSIString());
    
    SendNewUserMethod = GetClassStaticMethod("sendNewUser", "(Ljava/lang/String;Ljava/lang/String;)V");
    SendPayUserMethod = GetClassStaticMethod("sendPayUser", "(Ljava/lang/String;DLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");;
}

void FAndroidJavaCafeSdkStatistics::SendNewUser(FString GameUserId, FString Market)
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(Class,
        SendNewUserMethod.Method,
        FJavaClassObject::GetJString(GameUserId),
        FJavaClassObject::GetJString(Market)
        );
}

void FAndroidJavaCafeSdkStatistics::SendPayUser(FString GameUserId, double Pay, FString ProductCode, FString Currency, FString Market)
{
    JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
    
    JEnv->CallStaticVoidMethod(Class,
        SendPayUserMethod.Method,
        FJavaClassObject::GetJString(GameUserId),
        Pay,
        FJavaClassObject::GetJString(ProductCode),
        FJavaClassObject::GetJString(Currency),
        FJavaClassObject::GetJString(Market)
        );
}

FJavaClassMethod FAndroidJavaCafeSdkStatistics::GetClassStaticMethod(const char* MethodName, const char* FuncSig) const
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

FName FAndroidJavaCafeSdkStatistics::GetClassName()
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
