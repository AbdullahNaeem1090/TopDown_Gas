// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"
#include "GAS/AuraBaseAbilitySystemComponent.h"
#include "GAS/AuraBaseAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{

	AbilityComponent = CreateDefaultSubobject<UAuraBaseAbilitySystemComponent>("AbilityComponent");
	AbilityComponent->SetIsReplicated(true);
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);


	AttributeSet = CreateDefaultSubobject<UAuraBaseAttributeSet>("AbilitySet");

	SetNetUpdateFrequency(100.f);

}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilityComponent;
}

UAttributeSet* AAuraPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
