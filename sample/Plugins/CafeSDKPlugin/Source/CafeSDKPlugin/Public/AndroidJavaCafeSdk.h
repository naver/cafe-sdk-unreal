#pragma once

#if PLATFORM_ANDROID

#include "Core.h"
#include "Android/AndroidJava.h"

class FAndroidJavaCafeSdk  : public FJavaClassObject
{
public:
    FAndroidJavaCafeSdk();
    void ShowMessage();
    
private:
    static FName GetClassName();
    
    FJavaClassMethod InitMethod;
    FJavaClassMethod ShowMessageMethod;
};

#endif // PLATFORM_ANDROID
