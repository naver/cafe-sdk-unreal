// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#import <NaverCafeSDK/NCSDKStatistics.h>

class FIOSCafeSdkStatistics
{
public:
    FIOSCafeSdkStatistics();
    
    void SendNewUser(FString GameUserId, FString Market);
    void SendPayUser(FString GameUserId, double Pay, FString ProductCode, FString Currency, FString Market);
    
private:
};

FIOSCafeSdkStatistics* GetSharedCafeSdkStatistics();
