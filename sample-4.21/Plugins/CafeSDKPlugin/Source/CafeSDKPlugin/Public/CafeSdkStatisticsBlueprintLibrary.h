// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"
#include "CafeSdkStatisticsBlueprintLibrary.generated.h"

UCLASS()
class CAFESDKPLUGIN_API UCafeSdkStatisticsBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()
    
    /* 통계 관련 상수. */
    static const FString kCurrencyNone;
    static const FString kCurrencyWon;
    static const FString kCurrencyDollar;
    
    static const FString kMarketNone;
    static const FString kMarketOne;
    static const FString kMarketGoogle;
    static const FString kMarketApple;
    
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk Statistics")
    static void SendNewUser(FString GameUserId, FString Market);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk Statistics")
    static void SendPayUser(FString GameUserId, float Pay, FString ProductCode, FString Currency, FString Market);
};
