// Copyright 2016 NAVER Corp. All rights reserved.

#pragma once

#include "CoreUObject.h"
#include "Engine.h"
#include "ModuleManager.h"

class FCafeSDKPluginModule : public IModuleInterface
{
public:
    
    /**
     * Singleton-like access to this module's interface.  This is just for convenience!
     * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
     *
     * @return Returns singleton instance, loading the module on demand if needed
     */
    static inline FCafeSDKPluginModule& Get()
    {
        return FModuleManager::LoadModuleChecked< FCafeSDKPluginModule >( "CafeSDKPlugin" );
    }
    
    /**
     * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
     *
     * @return True if the module is loaded and ready to use
     */
    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded( "CafeSDKPlugin" );
    }
    
    DECLARE_MULTICAST_DELEGATE(FOnCafeSdkStarted);
    DECLARE_MULTICAST_DELEGATE(FOnCafeSdkStopped);
    DECLARE_MULTICAST_DELEGATE_OneParam(FOnCafeSdkClickAppSchemeBanner, const FString& /*AppScheme*/);
    DECLARE_MULTICAST_DELEGATE(FOnCafeSdkJoined);
    DECLARE_MULTICAST_DELEGATE_OneParam(FOnCafeSdkPostedArticle, int32 /*MenuId*/);
    DECLARE_MULTICAST_DELEGATE_OneParam(FOnCafeSdkPostedComment, int32 /*ArticleId*/);
    
    static FOnCafeSdkStarted OnCafeSdkStarted;
    static FOnCafeSdkStopped OnCafeSdkStopped;
    static FOnCafeSdkClickAppSchemeBanner OnCafeSdkClickAppSchemeBanner;
    static FOnCafeSdkJoined OnCafeSdkJoined;
    static FOnCafeSdkPostedArticle OnCafeSdkPostedArticle;
    static FOnCafeSdkPostedComment OnCafeSdkPostedComment;
};
