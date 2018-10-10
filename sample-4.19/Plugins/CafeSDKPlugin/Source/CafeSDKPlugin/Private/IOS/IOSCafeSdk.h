// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#import <NaverCafeSDK/NCSDKManager.h>
#import <NaverCafeSDK/NCSDKLoginManager.h>
#import <NaverCafeSDK/NCSDKStatistics.h>
#import <NaverCafeSDK/NCNaverLoginManager.h>
#import <NaverCafeSDK/NCSDKRecordManager.h>
#include "CafeSdk.h"

class FIOSCafeSdk : public ICafeSdk, public INaverIdLogin
{
public:
    FIOSCafeSdk();
    
    void Init(FString ClientId, FString ClientSecret, int32 CafeId);
    void InitGlobal(FString ConsumerKey, FString ConsumerSecret, int32 CommunityId, int32 LoungeNo);
    
    void SetChannelCode(FString ChannelCode) const;
    
    void StartHome() const;
    void StartNotice() const;
    void StartEvent() const;
    void StartMenu() const;
    void StartProfile() const;
    void StartWrite() const;
    void StartImageWrite(FString ImageUri) const;
    void StartVideoWrite(FString VideoUri) const;
    
    void Stop() const;
    
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
    
    // recording.
    void InitRecord();
    void StartRecord();
    void StopRecord();
private:
    void SetParentViewController() const;
};

@interface CafeCallbackObject : NSObject <NCSDKManagerDelegate, NCNaverLoginManagerDelegate, NCSDKRecordManagerDelegate>
+ (CafeCallbackObject*)getSharedInstance;
- (void)setSDKInfoWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret cafeId:(NSInteger)cafeId;
- (void)setGlobalConsumerKey:(NSString *)globalConsumerKey globalConsumerSecret:(NSString *)globalConsumerSecret globalCommunityNo:(NSInteger)globalCommunityNo globalLoungeNo:(NSInteger)globalLoungeNo;
- (void)setChannelCode:(NSString *)channelCode;
- (void)startHome;
- (void)startNotice;
- (void)startEvent;
- (void)startMenu;
- (void)startProfile;
- (void)stopSDK;
- (void)startMore;
- (void)startMainThreadWithBlock:(void (^)(void))block;
- (void)requestNaverLogin;
- (void)initRecord;
- (void)startRecord;
- (void)stopRecord;
@end

