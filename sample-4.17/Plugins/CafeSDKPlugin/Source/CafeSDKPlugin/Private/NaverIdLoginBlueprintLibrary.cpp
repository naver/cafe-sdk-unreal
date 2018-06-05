// Copyright 2017 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "NaverIdLoginBlueprintLibrary.h"
#include "CafeSdk.h"


UNaverIdLoginBlueprintLibrary::UNaverIdLoginBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    // do nothing.
}

void UNaverIdLoginBlueprintLibrary::Init(FString ClientId, FString ClientSecret)
{
    if (GetSharedNaverIdLogin() == nullptr) return;
    GetSharedNaverIdLogin()->Init(ClientId, ClientSecret);
}

void UNaverIdLoginBlueprintLibrary::Login()
{
    if (GetSharedNaverIdLogin() == nullptr) return;
    GetSharedNaverIdLogin()->Login();
}

void UNaverIdLoginBlueprintLibrary::Logout()
{
    if (GetSharedNaverIdLogin() == nullptr) return;
    GetSharedNaverIdLogin()->Logout();
}

bool UNaverIdLoginBlueprintLibrary::IsLogin()
{
    if (GetSharedNaverIdLogin() == nullptr) return false;
    return GetSharedNaverIdLogin()->IsLogin();
}

void UNaverIdLoginBlueprintLibrary::GetProfile()
{
    if (GetSharedNaverIdLogin() == nullptr) return;
    GetSharedNaverIdLogin()->GetProfile();
}
