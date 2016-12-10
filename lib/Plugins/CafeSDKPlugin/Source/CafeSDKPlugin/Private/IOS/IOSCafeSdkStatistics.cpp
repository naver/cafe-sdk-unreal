// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "IOSPlatformString.h"
#include "IOSCafeSdkStatistics.h"

FIOSCafeSdkStatistics* GetSharedCafeSdkStatistics()
{
    static FIOSCafeSdkStatistics* CafeSdkStatistics = nullptr;
    if (CafeSdkStatistics == nullptr)
    {
        CafeSdkStatistics = new FIOSCafeSdkStatistics();
    }
    return CafeSdkStatistics;
}

FIOSCafeSdkStatistics::FIOSCafeSdkStatistics()
{
}

void FIOSCafeSdkStatistics::SendNewUser(FString GameUserId, FString Market)
{
    [NCSDKStatistics sendNewUser:GameUserId.GetNSString()
                       andMarket:Market.GetNSString()];
}

void FIOSCafeSdkStatistics::SendPayUser(FString GameUserId, double Pay, FString ProductCode, FString Currency, FString Market)
{
    [NCSDKStatistics sendPayUser:GameUserId.GetNSString()
                          andPay:Pay
                  andProductCode:ProductCode.GetNSString()
                     andCurrency:Currency.GetNSString()
                       andMarket:Market.GetNSString()];
}
