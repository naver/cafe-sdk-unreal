// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#include "Core.h"
#include "AndroidJava.h"

class FAndroidJavaCafeSdk : public FJavaClassObject
{
public:
    FAndroidJavaCafeSdk();
    
    void Init(FString ClientId, FString ClientSecret, int32 CafeId);
    void InitGlobal(FString ClientId, int32 CafeId, FString DefaultChannelCode);
    
    void StartMore();
    
private:
    static FName GetClassName();
    
    FJavaClassMethod InitMethod;
    FJavaClassMethod InitGlobalMethod;
    FJavaClassMethod StartMoreMethod;
};

FAndroidJavaCafeSdk* GetSharedCafeSdk();
