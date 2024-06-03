// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InputActionValue.h"
#include "../UnrealStudy0325.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "URSPawn.generated.h"

UCLASS()
class UNREALSTUDY0325_API AURSPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AURSPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleAnywhere, Category=Collision)
	UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnywhere, Category=Visual)
	USkeletalMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, Category=Camera)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category=Camera)
	UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, Category=Movement)
	UFloatingPawnMovement* Movement;

	//향상된 인풋 시스템
	UPROPERTY(VisibleAnywhere, Category = Input)
	class UInputMappingContext* DefaultContext;

	UPROPERTY(VisibleAnywhere, Category = Input)
	class UInputAction* MovementAction;

private:
	void Move(const FInputActionValue& Value);
};
