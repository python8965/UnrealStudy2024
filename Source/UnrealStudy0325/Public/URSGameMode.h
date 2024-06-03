// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../UnrealStudy0325.h"
#include "GameFramework/GameModeBase.h"
#include "URSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY0325_API AURSGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AURSGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;
};
