// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#include "Core.h"
#include "AndroidJava.h"
#include "CafeSdk.h"

class FAndroidJavaCafeSdk : public FJavaClassObject, public ICafeSdk, public INaverIdLogin
{
public:
    FAndroidJavaCafeSdk();
    
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
    static FName GetClassName();
    
    FJavaClassMethod InitMethod;
    FJavaClassMethod InitGlobalMethod;
    FJavaClassMethod StartMoreMethod;
    
    FJavaClassMethod LoginMethod;
    FJavaClassMethod LogoutMethod;
    FJavaClassMethod IsLoginMethod;
    FJavaClassMethod GetProfileMethod;
    
    // Glink class.
    static FName GetGlinkClassName();
    FJavaClassMethod GetGlinkClassStaticMethod(const char* MethodName, const char* FuncSig) const;
    
    void StartTab(const FJavaClassMethod& JavaClassMethod) const;
    
    jclass GlinkClass;
    FJavaClassMethod SetChannelCodeMethod;
    FJavaClassMethod StartHomeMethod;
    FJavaClassMethod StartNoticeMethod;
    FJavaClassMethod StartEventMethod;
    FJavaClassMethod StartMenuMethod;
    FJavaClassMethod StartProfileMethod;
    FJavaClassMethod StartWriteMethod;
    FJavaClassMethod StartImageWriteMethod;
    FJavaClassMethod StartVideoWriteMethod;
    FJavaClassMethod SetThemeColorMethod;
    FJavaClassMethod IsShowMethod;
    FJavaClassMethod SyncGameUserIdMethod;
    FJavaClassMethod StartWidgetMethod;
    FJavaClassMethod StopWidgetMethod;
    FJavaClassMethod ShowWidgetWhenUnloadSdkMethod;
    FJavaClassMethod SetWidgetStartPositionMethod;
    FJavaClassMethod SetUseVideoRecordMethod;
    FJavaClassMethod SetUseScreenshotMethod;
    FJavaClassMethod GetAndroidVersionMethod;
    
    // Statistics class.
    static FName GetStatisticsClassName();
    FJavaClassMethod GetStatisticsClassStaticMethod(const char* MethodName, const char* FuncSig) const;
    
    jclass StatisticsClass;
    FJavaClassMethod SendNewUserMethod;
    FJavaClassMethod SendPayUserMethod;
};
