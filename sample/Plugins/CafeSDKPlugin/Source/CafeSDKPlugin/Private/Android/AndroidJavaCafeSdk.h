// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#include "Core.h"
#include "AndroidJava.h"

class FAndroidJavaCafeSdk : public FJavaClassObject
{
public:
    FAndroidJavaCafeSdk();
    void Init(FString ClientId, FString ClientSecret, int32 CafeId);
    
private:
    static FName GetClassName();
    
    FJavaClassMethod InitMethod;
};

FAndroidJavaCafeSdk* GetSharedCafeSdk();
