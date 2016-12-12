// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "CafeSdkStatisticsBlueprintLibrary.h"

const FString UCafeSdkStatisticsBlueprintLibrary::kCurrencyNone("NONE");
const FString UCafeSdkStatisticsBlueprintLibrary::kCurrencyWon("WON");
const FString UCafeSdkStatisticsBlueprintLibrary::kCurrencyDollar("DOLLAR");

const FString UCafeSdkStatisticsBlueprintLibrary::kMarketNone("NONE");
const FString UCafeSdkStatisticsBlueprintLibrary::kMarketOne("ONE");
const FString UCafeSdkStatisticsBlueprintLibrary::kMarketGoogle("GOOGLE");
const FString UCafeSdkStatisticsBlueprintLibrary::kMarketApple("APPLE");

#if PLATFORM_ANDROID

#include "Android/AndroidJavaCafeSdkStatistics.h"

UCafeSdkStatisticsBlueprintLibrary::UCafeSdkStatisticsBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    // do nothing.
}

void UCafeSdkStatisticsBlueprintLibrary::SendNewUser(FString GameUserId, FString Market)
{
    GetSharedCafeSdkStatistics()->SendNewUser(GameUserId, Market);
}

void UCafeSdkStatisticsBlueprintLibrary::SendPayUser(FString GameUserId, float Pay, FString ProductCode, FString Currency, FString Market)
{
    GetSharedCafeSdkStatistics()->SendPayUser(GameUserId, Pay, ProductCode, Currency, Market);
}

#elif PLATFORM_IOS

#include "IOS/IOSCafeSdk.h"

UCafeSdkStatisticsBlueprintLibrary::UCafeSdkStatisticsBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    // do nothing.
}

void UCafeSdkStatisticsBlueprintLibrary::SendNewUser(FString GameUserId, FString Market)
{
    // do nothing.
}

void UCafeSdkStatisticsBlueprintLibrary::SendPayUser(FString GameUserId, float Pay, FString ProductCode, FString Currency, FString Market)
{
    // do nothing.
}

#else

UCafeSdkStatisticsBlueprintLibrary::UCafeSdkStatisticsBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    // do nothing.
}

void UCafeSdkStatisticsBlueprintLibrary::SendNewUser(FString GameUserId, FString Market)
{
    // do nothing.
}

void UCafeSdkStatisticsBlueprintLibrary::SendPayUser(FString GameUserId, float Pay, FString ProductCode, FString Currency, FString Market)
{
    // do nothing.
}

#endif
