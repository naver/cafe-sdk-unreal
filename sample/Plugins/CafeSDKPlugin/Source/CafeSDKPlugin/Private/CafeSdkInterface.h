// Copyright 2017 NAVER Corp. All rights reserved.

#pragma once


class ICafeSdkInterface
{
public:
    virtual void Init(FString ClientId, FString ClientSecret, int32 CafeId) = 0;
    virtual void InitGlobal(FString ClientId, int32 CafeId, FString DefaultChannelCode) = 0;
    
    virtual void StartMore() = 0;
    
    virtual void StartHome() const = 0;
    virtual void StartNotice() const = 0;
    virtual void StartEvent() const = 0;
    virtual void StartMenu() const = 0;
    virtual void StartMenuById(int32 MenuId) const = 0;
    virtual void StartProfile() const = 0;
    virtual void StartWrite(int32 MenuId, FString Subject, FString Text) const = 0;
    virtual void StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri) const = 0;
    virtual void StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri) const = 0;
    
    virtual bool IsShow() const = 0;
    virtual void SyncGameUserId(FString GameUserId) const = 0;
    
    virtual void ShowWidgetWhenUnloadSdk(bool bUse) const = 0;
    virtual void StopWidget() const = 0;
    virtual void SetUseVideoRecord(bool bUse) const = 0;
    virtual void SetThemeColor(FString ThemeColorCSSString, FString TabBackgroundColorCSSString) const = 0;
    virtual void SetXButtonTypeClose(bool bUse) const = 0;
    
    virtual bool IsSupportedAndroidVersion() const = 0;
    
    virtual void SendNewUser(FString GameUserId, FString Market) = 0;
    virtual void SendPayUser(FString GameUserId, double Pay, FString ProductCode, FString Currency, FString Market) = 0;
};

ICafeSdkInterface* GetSharedCafeSdk();

bool IsCafeSdkAvailable();
