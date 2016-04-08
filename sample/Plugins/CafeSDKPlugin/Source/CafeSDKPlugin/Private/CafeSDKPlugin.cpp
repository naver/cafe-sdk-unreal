// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FCafeSDKPluginModule"

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
