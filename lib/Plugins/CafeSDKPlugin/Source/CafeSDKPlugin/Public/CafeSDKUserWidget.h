// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CafeSDKUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CAFESDKPLUGIN_API UCafeSDKUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = "Glink")
    void StartGlink();
	
	
	
};
