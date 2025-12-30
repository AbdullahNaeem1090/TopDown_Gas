// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"
#include "AbilitySystemComponent.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400,0.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

}

void AAuraCharacter::PossessedBy(AController* PlayerController)
{
	Super::PossessedBy(PlayerController);
	InitializeActorInfoForAbilityComponent();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitializeActorInfoForAbilityComponent();
}

void AAuraCharacter::InitializeActorInfoForAbilityComponent()
{
	AAuraPlayerState* ControlledPlayerState = GetPlayerState<AAuraPlayerState>();
	check(ControlledPlayerState);
	ControlledPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(ControlledPlayerState,this);
	AbilityComponent = ControlledPlayerState->GetAbilitySystemComponent();
	AttributeSet = ControlledPlayerState->GetAttributeSet();
}
