// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/AuraBaseUserWidget.h"


void UAuraBaseUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
