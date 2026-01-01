// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "GAS/AuraBaseAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	UAuraBaseAttributeSet* Aura_AttributeSet = CastChecked<UAuraBaseAttributeSet>(AuraAtrributeSet);

	OnHealthChanged.Broadcast(Aura_AttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(Aura_AttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallBacksToDependencies()
{
	UAuraBaseAttributeSet* Aura_AttributeSet = CastChecked<UAuraBaseAttributeSet>(AuraAtrributeSet);

	AuraASC->GetGameplayAttributeValueChangeDelegate(Aura_AttributeSet->GetHealthAttribute()).AddUObject(this, &HealthChanged);
	AuraASC->GetGameplayAttributeValueChangeDelegate(Aura_AttributeSet->GetMaxHealthAttribute()).AddUObject(this, &MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue);

}
void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue);
}
