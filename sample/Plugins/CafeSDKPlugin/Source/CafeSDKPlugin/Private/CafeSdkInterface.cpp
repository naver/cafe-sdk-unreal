// Copyright 2017 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJavaCafeSdk.h"

ICafeSdkInterface* GetSharedCafeSdk()
{
    static FAndroidJavaCafeSdk* CafeSdk = nullptr;
    if (CafeSdk == nullptr)
    {
        CafeSdk = new FAndroidJavaCafeSdk();
    }
    return CafeSdk;
}

#elif PLATFORM_IOS

#include "IOS/IOSCafeSdk.h"

ICafeSdkInterface* GetSharedCafeSdk()
{
    static FIOSCafeSdk* CafeSdk = nullptr;
    if (CafeSdk == nullptr)
    {
        CafeSdk = new FIOSCafeSdk();
    }
    return CafeSdk;
}

#else

#include "CafeSDKInterface.h"

ICafeSdkInterface* GetSharedCafeSdk()
{
    return nullptr;
}

#endif

bool IsCafeSdkAvailable()
{
    return GetSharedCafeSdk() != nullptr && GetSharedCafeSdk()->IsSupportedAndroidVersion();
}
