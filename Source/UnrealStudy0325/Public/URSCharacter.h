// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "../UnrealStudy0325.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "URSCharacter.generated.h"


UCLASS()
class UNREALSTUDY0325_API AURSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AURSCharacter();

	UPROPERTY(VisibleAnywhere, Category = Input)
	UInputMappingContext* DefaultContext;
	UPROPERTY(VisibleAnywhere, Category = Input)
	UInputAction* MovementAction;
	UPROPERTY(VisibleAnywhere, Category = Input)
	UInputAction* LookAction;
	UPROPERTY(VisibleAnywhere, Category = Input)
	UInputAction* ViewChangeAction;
	UPROPERTY(VisibleAnywhere, Category = Input)
	UInputAction* JumpAction;
	UPROPERTY(VisibleAnywhere, Category = Input)
	UInputAction* AttackAction;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	enum class EControlMode
	{
		GTA,
		LostArk,
	};
	EControlMode CurrentControlMode = EControlMode::GTA;
	FVector DirectionToMove = FVector::ZeroVector;

	float ArmLengthTo = 0.0f;
	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;
	

	void SetControlMode(EControlMode ControlMode);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void PostInitializeComponents() override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(VisibleAnywhere, Category=Camera)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category=Camera)
	UCameraComponent* Camera;
private:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void ViewChange();
	void Attack();

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	void AttackStartComboState();
	void AttackEndComboState();
	void AttackCheck();
private:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Attack, Meta=(AllowPrivateAccess = true))
	bool bIsAttacking;

	UPROPERTY()
	class UURSAnimInstance* URSAnim;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Attack, Meta = (AllowPrivateAccess=true))
	bool bCanNextCombo;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Attack, Meta = (AllowPrivateAccess=true))
	bool bIsComboInputOn;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Attack, Meta = (AllowPrivateAccess=true))
	int32 CurrentCombo;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Attack, Meta = (AllowPrivateAccess=true))
	int32 MaxCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Attack, Meta = (AllowPrivateAccess=true))
	float AttackRange;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category=Attack, Meta = (AllowPrivateAccess=true))
	float AttackRadius;
};
