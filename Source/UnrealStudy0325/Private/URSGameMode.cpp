// Fill out your copyright notice in the Description page of Project Settings.


#include "URSGameMode.h"

#include "URSCharacter.h"
#include "URSPlayerController.h"

AURSGameMode::AURSGameMode()
{
	DefaultPawnClass = AURSCharacter::StaticClass();
	PlayerControllerClass = AURSPlayerController::StaticClass();
}

void AURSGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}
