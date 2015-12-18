// Fill out your copyright notice in the Description page of Project Settings.

#include "CafeSDKPluginPrivatePCH.h"
#include "CafeSDKUserWidget.h"
#include "Glink/UGlinkUnreal.h"



void UCafeSDKUserWidget::StartGlink() {
    UGlinkUnreal *glinkUnreal = NewObject<UGlinkUnreal>();
    glinkUnreal->executeMain();

}