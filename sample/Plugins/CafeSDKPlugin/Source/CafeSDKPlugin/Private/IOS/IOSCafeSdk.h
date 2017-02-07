// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#import <NaverCafeSDK/NCSDKManager.h>
#import <NaverCafeSDK/NCSDKLoginManager.h>
#include "CafeSDKInterface.h"

class FIOSCafeSdk public ICafeSdkInterface
{
public:
    FIOSCafeSdk();
    
    void Init(FString ClientId, FString ClientSecret, int32 CafeId) const;
    void InitGlobal(FString ClientId, int32 CommunityId, FString DefaultChannelCode) const;
    
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
    
    void ShowWidgetWhenUnloadSdk(bool bUse) const;
    void StopWidget() const;
    void SetUseVideoRecord(bool bUse) const;
    void SetThemeColor(FString ThemeColorCSSString, FString TabBackgroundColorCSSString) const;
    void SetXButtonTypeClose(EXButtonType Type) const;

    void StartMore() const;
    
    bool IsSupportedOSVersion() const;
    
private:
    void SetParentViewController() const;
};

@interface CafeCallbackObject : NSObject <NCSDKManagerDelegate>
+ (CafeCallbackObject*)getSharedInstance;
- (void)setSDKInfoWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret cafeId:(NSInteger)cafeId;
- (void)setGlobalSDKInfoWithClientId:(NSString *)clientId communityId:(NSInteger)communityId defaultChannelCode:(NSString *)channelCode;
- (void)startHome;
- (void)startNotice;
- (void)startEvent;
- (void)startMenu;
- (void)startProfile;
- (void)startMore;
- (void)startMainThreadWithBlock:(void (^)(void))block;
@end

