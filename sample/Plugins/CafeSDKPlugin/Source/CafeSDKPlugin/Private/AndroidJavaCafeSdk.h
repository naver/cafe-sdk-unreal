#pragma once

#if PLATFORM_ANDROID

#include "Core.h"
#include "Android/AndroidJava.h"

class FAndroidJavaCafeSdk  : public FJavaClassObject
{
public:
    FAndroidJavaCafeSdk();
    void Init(FString ClientId, FString ClientSecret, int32 CafeId) const;
    
private:
    static FName GetClassName();
    
    FJavaClassMethod InitMethod;
};

#endif // PLATFORM_ANDROID
