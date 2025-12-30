// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(SubSystem);
	SubSystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);

	SetInputMode(InputMode);
	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputValue)
{
	const FVector2d InputAxisValue = InputValue.Get<FVector2D>();
	const FRotator ControllerRotation = GetControlRotation();
	const FRotator ControllerYawRotation(0.f, ControllerRotation.Yaw, 0.f);
	const FVector ForwardVector = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* PlayerPawn = GetPawn<APawn>()) {
		PlayerPawn->AddMovementInput(ForwardVector, InputAxisValue.X);
		PlayerPawn->AddMovementInput(RightVector, InputAxisValue.Y);
	 }
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (!HitResult.bBlockingHit) return;

	LastActorUnderCursor = CurrentActorUnderCursor;
	CurrentActorUnderCursor = HitResult.GetActor();

	if (LastActorUnderCursor == nullptr) {
		if (CurrentActorUnderCursor) CurrentActorUnderCursor->HighlightEnemy();
	}
	else {
		if (!CurrentActorUnderCursor) LastActorUnderCursor->UnHighlightEnemy();
		else if (CurrentActorUnderCursor != LastActorUnderCursor) 
		{
			LastActorUnderCursor->UnHighlightEnemy();
			CurrentActorUnderCursor->HighlightEnemy();
		}
	}

}
