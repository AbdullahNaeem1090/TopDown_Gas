// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraEnemy.h"
#include "Aura/Aura.h"
#include "GAS/AuraBaseAbilitySystemComponent.h"
#include "GAS/AuraBaseAttributeSet.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECR_Block);

	AbilityComponent = CreateDefaultSubobject<UAuraBaseAbilitySystemComponent>("AbilityComponent");
	AbilityComponent->SetIsReplicated(true);
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAuraBaseAttributeSet>("AbilitySet");

}

void AAuraEnemy::HighlightEnemy()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(Hightlite_Strength);
    WeaponMesh->SetRenderCustomDepth(true);
	WeaponMesh->SetCustomDepthStencilValue(Hightlite_Strength);
}

void AAuraEnemy::UnHighlightEnemy()
{
	GetMesh()->SetRenderCustomDepth(false);
	WeaponMesh->SetRenderCustomDepth(false);
}

void AAuraEnemy::BeginPlay()
{
	AbilityComponent->InitAbilityActorInfo(this, this);
}
