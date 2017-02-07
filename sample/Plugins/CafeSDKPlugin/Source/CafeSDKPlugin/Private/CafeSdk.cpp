// Copyright 2017 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJavaCafeSdk.h"

FAndroidJavaCafeSdk* GetSharedAndroidJavaCafeSdk()
{
    static FAndroidJavaCafeSdk* CafeSdk = nullptr;
    if (CafeSdk == nullptr)
    {
        CafeSdk = new FAndroidJavaCafeSdk();
    }
    return CafeSdk;
}

ICafeSdk* GetSharedCafeSdk()
{
    return GetSharedAndroidJavaCafeSdk();
}

INaverIdLogin* GetSharedNaverIdLogin()
{
    return GetSharedAndroidJavaCafeSdk();
}

#elif PLATFORM_IOS

#include "IOS/IOSCafeSdk.h"

ICafeSdk* GetSharedCafeSdk()
{
    static FIOSCafeSdk* CafeSdk = nullptr;
    if (CafeSdk == nullptr)
    {
        CafeSdk = new FIOSCafeSdk();
    }
    return CafeSdk;
}

INaverIdLogin* GetSharedNaverIdLogin()
{
    return nullptr;
}

#else

#include "CafeSdk.h"

ICafeSdk* GetSharedCafeSdk()
{
    return nullptr;
}

INaverIdLogin* GetSharedNaverIdLogin()
{
    return nullptr;
}

#endif

bool IsCafeSdkAvailable()
{
    return GetSharedCafeSdk() != nullptr && GetSharedCafeSdk()->IsSupportedAndroidVersion();
}
