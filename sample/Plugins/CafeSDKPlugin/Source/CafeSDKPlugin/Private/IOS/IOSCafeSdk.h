// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#import <NaverCafeSDK/NCSDKManager.h>
#import <NaverCafeSDK/NCSDKLoginManager.h>
#import <NaverCafeSDK/NCSDKStatistics.h>
#import <NaverCafeSDK/NCNaverLoginManager.h>
#include "CafeSdk.h"

class FIOSCafeSdk : public ICafeSdk, public INaverIdLogin
{
public:
    FIOSCafeSdk();
    
    void Init(FString ClientId, FString ClientSecret, int32 CafeId);
    void InitGlobal(FString ClientId, int32 CafeId);
    
    void SetChannelCode(FString ChannelCode) const;
    
    void StartHome() const;
    void StartNotice() const;
    void StartEvent() const;
    void StartMenu() const;
    void StartProfile() const;
    void StartWrite() const;
    void StartImageWrite(FString ImageUri) const;
    void StartVideoWrite(FString VideoUri) const;
    
    void StartMore();
    
    bool IsShow() const;
    void SyncGameUserId(FString GameUserId) const;
    
    void StartWidget() const;
    void StopWidget() const;
    void ShowWidgetWhenUnloadSdk(bool bUse) const;
    void SetWidgetStartPosition(bool bIsLeft, int32 HeightPercentage) const;
    
    void SetUseVideoRecord(bool bUse) const;
    void SetUseScreenShot(bool bUse) const;
    void SetThemeColor(FString ThemeColorCSSString, FString TabBackgroundColorCSSString) const;
    
    bool IsSupportedOSVersion() const;
    
    // statistics.
    void SendNewUser(FString GameUserId, FString Market);
    void SendPayUser(FString GameUserId, double Pay, FString ProductCode, FString Currency, FString Market);
    
    // login.
    void Init(FString ClientId, FString ClientSecret);
    void Login();
    void Logout();
    bool IsLogin();
    void GetProfile();
    
private:
    void SetParentViewController() const;
};

@interface CafeCallbackObject : NSObject <NCSDKManagerDelegate, NCNaverLoginManagerDelegate>
+ (CafeCallbackObject*)getSharedInstance;
- (void)setSDKInfoWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret cafeId:(NSInteger)cafeId;
- (void)setGlobalSDKInfoWithClientId:(NSString *)clientId communityId:(NSInteger)communityId;
- (void)setChannelCode:(NSString *)channelCode;
- (void)startHome;
- (void)startNotice;
- (void)startEvent;
- (void)startMenu;
- (void)startProfile;
- (void)startMore;
- (void)startMainThreadWithBlock:(void (^)(void))block;
- (void)requestNaverLogin;
@end

