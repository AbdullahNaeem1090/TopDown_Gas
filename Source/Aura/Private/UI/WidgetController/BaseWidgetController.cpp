// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/BaseWidgetController.h"

void UBaseWidgetController::SetWidgetControllerParams(const FBaseWidgetControllerParams& WC)
{
	AuraASC = WC.ASC;
	AuraAtrributeSet = WC.AtrributeSet;
	AuraPlayerController = WC.PlayerController;
	AuraPlayerState = WC.PlayerState;
}

void UBaseWidgetController::BroadcastInitialValues()
{
	// will be overridden by child classes
}

void UBaseWidgetController::BindCallBacksToDependencies()
{
	// will be overridden by child classes
}
