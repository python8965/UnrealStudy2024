// Fill out your copyright notice in the Description page of Project Settings.


#include "URSAnimInstance.h"

UURSAnimInstance::UURSAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	bIsInAir = false;
	bIsDead = false;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT("/Game/Resource/Chapter5/SK_Mannequin_Skeleton_Montage.SK_Mannequin_Skeleton_Montage"));
	if (ATTACK_MONTAGE.Succeeded())
		AttackMontage = ATTACK_MONTAGE.Object;
}

void UURSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (!::IsValid(Pawn)) {return;}

	if (bIsDead) {return;}
	
	CurrentPawnSpeed = Pawn->GetVelocity().Size();

	auto Character = Cast<ACharacter>(Pawn);

	if (Character)
	{
		bIsInAir = Character->GetMovementComponent()->IsFalling();
	}
}

void UURSAnimInstance::PlayAttackMontage()
{
	UNREALSTUDY_CHECK(!bIsDead);
	Montage_Play(AttackMontage, 1.0f);
}

void UURSAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	UNREALSTUDY_CHECK(Montage_IsPlaying(AttackMontage));
	UNREALSTUDY_CHECK(!bIsDead);
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

void UURSAnimInstance::AnimNotify_AttackHitCheck()
{
	OnAttackHitCheckDelegate.Broadcast();
}

void UURSAnimInstance::AnimNotify_NextAttackCheck()
{
	OnNextAttackCheckDelegate.Broadcast();
}

FName UURSAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	UNREALSTUDY_CHECK(FMath::IsWithinInclusive<int32>(Section, 1, 4), NAME_None);

	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}
