// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../UnrealStudy0325.h"
#include "GameFramework/Actor.h"
#include "URSWeapon.generated.h"

UCLASS()
class UNREALSTUDY0325_API AURSWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AURSWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category= Weapon)
	USkeletalMeshComponent* Weapon;
};
