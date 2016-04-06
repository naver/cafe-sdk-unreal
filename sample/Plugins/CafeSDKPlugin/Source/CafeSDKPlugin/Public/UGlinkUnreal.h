#pragma once
#include "UGlinkUnreal.generated.h"

UCLASS()
class CAFESDKPLUGIN_API UGlinkUnreal : public UObject
{
    GENERATED_UCLASS_BODY()
    
public:
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSDK")
    void StartHome();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSDK")
    void StartProfile();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSDK")
    void StartNotice();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSDK")
    void StartEvent();
};
