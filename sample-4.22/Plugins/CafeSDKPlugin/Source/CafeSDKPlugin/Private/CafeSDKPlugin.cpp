// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FCafeSDKPluginModule"

FCafeSDKPluginModule::FOnCafeSdkStarted FCafeSDKPluginModule::OnCafeSdkStarted;
FCafeSDKPluginModule::FOnCafeSdkStopped FCafeSDKPluginModule::OnCafeSdkStopped;
FCafeSDKPluginModule::FOnCafeSdkClickAppSchemeBanner FCafeSDKPluginModule::OnCafeSdkClickAppSchemeBanner;
FCafeSDKPluginModule::FOnCafeSdkJoined FCafeSDKPluginModule::OnCafeSdkJoined;
FCafeSDKPluginModule::FOnCafeSdkPostedArticle FCafeSDKPluginModule::OnCafeSdkPostedArticle;
FCafeSDKPluginModule::FOnCafeSdkPostedComment FCafeSDKPluginModule::OnCafeSdkPostedComment;
FCafeSDKPluginModule::FOnCafeSdkRecordFinish FCafeSDKPluginModule::OnCafeSdkRecordFinish;
FCafeSDKPluginModule::FOnCafeSdkDidVote FCafeSDKPluginModule::OnCafeSdkDidVote;
FCafeSDKPluginModule::FOnLoggedIn FCafeSDKPluginModule::OnLoggedIn;
FCafeSDKPluginModule::FOnGetProfile FCafeSDKPluginModule::OnGetProfile;
FCafeSDKPluginModule::FOnStartRecord FCafeSDKPluginModule::OnStartRecord;
FCafeSDKPluginModule::FOnErrorRecord FCafeSDKPluginModule::OnErrorRecord;
FCafeSDKPluginModule::FOnFinishRecord FCafeSDKPluginModule::OnFinishRecord;

class CafeSDKPluginModule : public FCafeSDKPluginModule
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( CafeSDKPluginModule, CafeSDKPlugin )



void CafeSDKPluginModule::StartupModule()
{
    // This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void CafeSDKPluginModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}
