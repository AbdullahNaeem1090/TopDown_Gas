// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraBaseCharacter.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraBaseCharacter
{
	GENERATED_BODY()

public:
	AAuraCharacter();
	virtual void PossessedBy(AController* PlayerController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitializeActorInfoForAbilityComponent();	

	
};
