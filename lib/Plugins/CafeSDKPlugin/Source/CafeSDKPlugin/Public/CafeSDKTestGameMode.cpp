// Fill out your copyright notice in the Description page of Project Settings.

#include "CafeSDKPluginPrivatePCH.h"
#include "CafeSDKTestGameMode.h"

#include "Glink/UGlinkUnreal.h"


void ACafeSDKTestGameMode::BeginPlay()
{
    Super::BeginPlay();
    StartGlink(StartingWidgetClass);
}

void ACafeSDKTestGameMode::StartGlink(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurrentWidget != nullptr)
    {
//        CurrentWidget->RemoveFromViewport();
//        CurrentWidget = nullptr;

        //UGlinkUnreal glinkUnreal;
        //glinkUnreal.executeMain();

    }
    if (NewWidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }

}

