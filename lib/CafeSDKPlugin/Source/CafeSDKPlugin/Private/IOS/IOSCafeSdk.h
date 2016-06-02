// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#import <NaverCafeSDK/NCSDKManager.h>
#import <NaverCafeSDK/NCSDKLoginManager.h>
#import <NaverCafeSDK/NCWidget.h>
class FIOSCafeSdk
{
public:
    FIOSCafeSdk();
    
    void Init(FString ClientId, FString ClientSecret, int32 CafeId) const;
    
    void StartHome() const;
    void StartNotice() const;
    void StartEvent() const;
    void StartMenu() const;
    void StartMenuById(int32 MenuId) const;
    void StartProfile() const;
    void StartWrite(int32 MenuId, FString Subject, FString Text) const;
    void StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri) const;
    void StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri) const;
    
    bool IsShow() const;
    void SyncGameUserId(FString GameUserId) const;
    
    void StartMore() const;
    
private:
    void SetParentViewController() const;
};

FIOSCafeSdk* GetSharedCafeSdk();

@interface CafeCallbackObject : NSObject <NCSDKManagerDelegate, NCWidgetDelegate>
@end

