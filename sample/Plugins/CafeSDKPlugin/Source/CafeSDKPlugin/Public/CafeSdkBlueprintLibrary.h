
#pragma once

#include "CafeSdkBlueprintLibrary.generated.h"

UCLASS()
class CAFESDKPLUGIN_API UCafeSdkBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartHome();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartNotice();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartEvent();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartMenu();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
    static void StartProfile();
};
