// Fill out your copyright notice in the Description page of Project Settings.


#include "URSPlayerController.h"

void AURSPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UNREALSTUDY_SIMPLE(Warning);
}

void AURSPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	UNREALSTUDY_SIMPLE(Warning);
}

void AURSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	const FInputModeGameOnly InputMode;

	SetInputMode(InputMode);
}
