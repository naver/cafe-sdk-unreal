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
    static void StartHome();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartNotice();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartEvent();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartMenu();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartMenuById(int32 MenuId);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartProfile();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartWrite(int32 MenuId, FString Subject, FString Text);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartMore();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartWriteFromScreenshot();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static bool IsSupportedOSVersion();
};
