// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "CafeSdkStatisticsBlueprintLibrary.h"
#include "CafeSdk.h"


const FString UCafeSdkStatisticsBlueprintLibrary::kCurrencyNone("NONE");
const FString UCafeSdkStatisticsBlueprintLibrary::kCurrencyWon("WON");
const FString UCafeSdkStatisticsBlueprintLibrary::kCurrencyDollar("DOLLAR");

const FString UCafeSdkStatisticsBlueprintLibrary::kMarketNone("NONE");
const FString UCafeSdkStatisticsBlueprintLibrary::kMarketOne("ONE");
const FString UCafeSdkStatisticsBlueprintLibrary::kMarketGoogle("GOOGLE");
const FString UCafeSdkStatisticsBlueprintLibrary::kMarketApple("APPLE");


UCafeSdkStatisticsBlueprintLibrary::UCafeSdkStatisticsBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    // do nothing.
}

void UCafeSdkStatisticsBlueprintLibrary::SendNewUser(FString GameUserId, FString Market)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->SendNewUser(GameUserId, Market);
}

void UCafeSdkStatisticsBlueprintLibrary::SendPayUser(FString GameUserId, float Pay, FString ProductCode, FString Currency, FString Market)
{
    if (!IsCafeSdkAvailable()) return;
    GetSharedCafeSdk()->SendPayUser(GameUserId, Pay, ProductCode, Currency, Market);
}
