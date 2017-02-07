// Copyright 2017 NAVER Corp. All rights reserved.

#pragma once


class ICafeSdk
{
public:
    virtual void Init(FString ClientId, FString ClientSecret, int32 CafeId) = 0;
    virtual void InitGlobal(FString ClientId, int32 CafeId) = 0;
    
    virtual void StartHome() const = 0;
    virtual void StartNotice() const = 0;
    virtual void StartEvent() const = 0;
    virtual void StartMenu() const = 0;
    virtual void StartProfile() const = 0;
    
    virtual void StartWrite() const = 0;
    virtual void StartImageWrite(FString ImageUri) const = 0;
    virtual void StartVideoWrite(FString VideoUri) const = 0;
    
    virtual void StartMore() = 0;
    
    virtual bool IsShow() const = 0;
    virtual void SyncGameUserId(FString GameUserId) const = 0;
    
    virtual void StartWidget() const = 0;
    virtual void StopWidget() const = 0;
    virtual void ShowWidgetWhenUnloadSdk(bool bUse) const = 0;
    virtual void SetWidgetStartPosition(bool bIsLeft, int32 HeightPercentage) const = 0;
    
    virtual void SetUseVideoRecord(bool bUse) const = 0;
    virtual void SetThemeColor(FString ThemeColorCSSString, FString TabBackgroundColorCSSString) const = 0;
    
    virtual bool IsSupportedAndroidVersion() const = 0;
    
    virtual void SendNewUser(FString GameUserId, FString Market) = 0;
    virtual void SendPayUser(FString GameUserId, double Pay, FString ProductCode, FString Currency, FString Market) = 0;
};

class INaverIdLogin {
public:
    virtual void Init(FString ClientId, FString ClientSecret) = 0;
    virtual void Login() = 0;
    virtual void Logout() = 0;
    virtual bool IsLogin() = 0;
    
    /* docs: https://developers.naver.com/docs/login/profile */
    virtual void GetProfile() = 0;
};

ICafeSdk* GetSharedCafeSdk();
bool IsCafeSdkAvailable();

INaverIdLogin* GetSharedNaverIdLogin();
