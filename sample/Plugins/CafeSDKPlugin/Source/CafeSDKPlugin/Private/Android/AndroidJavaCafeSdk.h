// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#include "Core.h"
#include "AndroidJava.h"
#include "CafeSDKInterface.h"

class FAndroidJavaCafeSdk : public FJavaClassObject, public ICafeSdkInterface
{
public:
    FAndroidJavaCafeSdk();
    
    void Init(FString ClientId, FString ClientSecret, int32 CafeId);
    void InitGlobal(FString ClientId, int32 CafeId, FString DefaultChannelCode);
    
    void StartHome() const;
    void StartNotice() const;
    void StartEvent() const;
    void StartMenu() const;
    void StartMenuById(int32 MenuId) const;
    void StartProfile() const;
    void StartWrite(int32 MenuId, FString Subject, FString Text) const;
    void StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri) const;
    void StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri) const;
    
    void StartMore();
    
    bool IsShow() const;
    void SyncGameUserId(FString GameUserId) const;
    
    void ShowWidgetWhenUnloadSdk(bool bUse) const;
    void StopWidget() const;
    void SetUseVideoRecord(bool bUse) const;
    void SetThemeColor(FString ThemeColorCSSString, FString TabBackgroundColorCSSString) const;
    void SetXButtonTypeClose(bool bUse) const;
    
    bool IsSupportedAndroidVersion() const;
    
    // statistics.
    void SendNewUser(FString GameUserId, FString Market);
    void SendPayUser(FString GameUserId, double Pay, FString ProductCode, FString Currency, FString Market);
    
private:
    static FName GetClassName();
    
    FJavaClassMethod InitMethod;
    FJavaClassMethod InitGlobalMethod;
    FJavaClassMethod StartMoreMethod;
    
    // Glink class.
    static FName GetGlinkClassName();
    FJavaClassMethod GetGlinkClassStaticMethod(const char* MethodName, const char* FuncSig) const;
    
    void StartTab(const FJavaClassMethod& JavaClassMethod) const;
    
    jclass GlinkClass;
    FJavaClassMethod StartHomeMethod;
    FJavaClassMethod StartNoticeMethod;
    FJavaClassMethod StartEventMethod;
    FJavaClassMethod StartMenuMethod;
    FJavaClassMethod StartMenuByIdMethod;
    FJavaClassMethod StartProfileMethod;
    FJavaClassMethod StartWriteMethod;
    FJavaClassMethod StartImageWriteMethod;
    FJavaClassMethod StartVideoWriteMethod;
    FJavaClassMethod SetThemeColorMethod;
    FJavaClassMethod SetXButtonTypeCloseMethod;
    FJavaClassMethod IsShowMethod;
    FJavaClassMethod SyncGameUserIdMethod;
    FJavaClassMethod ShowWidgetWhenUnloadSdkMethod;
    FJavaClassMethod StopWidgetMethod;
    FJavaClassMethod SetUseVideoRecordMethod;
    FJavaClassMethod GetAndroidVersionMethod;
    
    // Statistics class.
    static FName GetStatisticsClassName();
    FJavaClassMethod GetStatisticsClassStaticMethod(const char* MethodName, const char* FuncSig) const;
    
    jclass StatisticsClass;
    FJavaClassMethod SendNewUserMethod;
    FJavaClassMethod SendPayUserMethod;
};
