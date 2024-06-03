// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../UnrealStudy0325.h"
#include "Animation/AnimInstance.h"
#include "URSAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);
/**
 * 
 */
UCLASS()
class UNREALSTUDY0325_API UURSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UURSAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void PlayAttackMontage();

	void JumpToAttackMontageSection(int32 NewSection);
public:
	FOnNextAttackCheckDelegate OnNextAttackCheckDelegate;
	FOnAttackHitCheckDelegate OnAttackHitCheckDelegate;
private:
	UFUNCTION()
	void AnimNotify_AttackHitCheck();
	UFUNCTION()
	void AnimNotify_NextAttackCheck();

	FName GetAttackMontageSectionName(int32 Section);
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Pawn, Meta = (AllowPrivateAccess = true))
	bool bIsInAir;


	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category=Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage; 
};
