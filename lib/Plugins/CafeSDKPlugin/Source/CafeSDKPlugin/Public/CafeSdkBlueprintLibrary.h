// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#include "CafeSdkBlueprintLibrary.generated.h"


UCLASS()
class CAFESDKPLUGIN_API UCafeSdkBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void Init(FString ClientId, FString ClientSecret, int32 CafeId);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void InitGlobal(FString ConsumerKey, FString ConsumerSecret, int32 CommunityId, int32 LoungeNo);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void SetChannelCode(FString ChannelCode);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartHome();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartNotice();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartEvent();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartMenu(int32 MenuNumber);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartProfile();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartWrite();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartImageWrite(FString ImageUri);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartVideoWrite(FString VideoUri);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartWriteFromScreenshot();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartMore();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void Stop();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartWidget();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StopWidget();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void ShowWidgetWhenUnloadSdk(bool bUse);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void SetWidgetStartPosition(bool bIsLeft, int32 HeightPercentage);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void SetUseVideoRecord(bool bUse);

    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void SetUseScreenShot(bool bUse);

    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void SyncGameUserId(FString GameUserId);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void SetThemeColor(FString ThemeColorCSSString, FString TabBackgroundColorCSSString);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void InitRecord();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartRecord();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StopRecord();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static bool IsSupportedOSVersion();
};
