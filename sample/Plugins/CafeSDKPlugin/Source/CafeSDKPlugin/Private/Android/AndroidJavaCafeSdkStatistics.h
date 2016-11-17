// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#include "Core.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJava.h"
#include "Runtime/Launch/Public/Android/AndroidJNI.h"

class FAndroidJavaCafeSdkStatistics
{
public:
    FAndroidJavaCafeSdkStatistics();
    
    void SendNewUser(FString GameUserId, FString Market);
    void SendPayUser(FString GameUserId, double Pay, FString ProductCode, FString Currency, FString Market);
    
private:
    static FName GetClassName();

    FJavaClassMethod GetClassStaticMethod(const char* MethodName, const char* FuncSig) const;
    
    jclass Class;
    FJavaClassMethod SendNewUserMethod;
    FJavaClassMethod SendPayUserMethod;
};

FAndroidJavaCafeSdkStatistics* GetSharedCafeSdkStatistics();
