// Copyright 2017 NAVER Corp. All rights reserved.

#pragma once

#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"
#include "NaverIdLoginBlueprintLibrary.generated.h"

UCLASS()
class CAFESDKPLUGIN_API UNaverIdLoginBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()
    
    UFUNCTION(BlueprintCallable, Category = "Naver Id Login")
    static void Init(FString ClientId, FString ClientSecret);
    
    UFUNCTION(BlueprintCallable, Category = "Naver Id Login")
    static void Login();
    
    UFUNCTION(BlueprintCallable, Category = "Naver Id Login")
    static void Logout();
    
    UFUNCTION(BlueprintCallable, Category = "Naver Id Login")
    static bool IsLogin();
    
    UFUNCTION(BlueprintCallable, Category = "Naver Id Login")
    static void GetProfile();
};
