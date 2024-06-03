// Fill out your copyright notice in the Description page of Project Settings.


#include "URSPawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

#define DEFAULT_SUB_OBJECT(X) CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));

// Sets default values
AURSPawn::AURSPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));

	RootComponent = Capsule;
	Mesh->SetupAttachment(Capsule);
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm);

	Capsule->SetCapsuleHalfHeight(88.0f);
	Capsule->SetCapsuleRadius(34.0f);

	Mesh -> SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f,-90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));

	if (SK_CARDBOARD.Succeeded())
	{
		Mesh->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	static ConstructorHelpers::FObjectFinder<UInputMappingContext>DEFAULT_CONTEXT
	(TEXT("/Game/UEStudy/PlayerInputMapping.PlayerInputMapping"));
	if (DEFAULT_CONTEXT.Succeeded())
		DefaultContext = DEFAULT_CONTEXT.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction>IA_MOVEMENT
	(TEXT("/Game/UEStudy/Movement.Movement"));
	if (IA_MOVEMENT.Succeeded())
		MovementAction = IA_MOVEMENT.Object;

	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(TEXT("/Game/Resource/Chapter5/AnimBP_Warrior.AnimBP_Warrior_C"));
	if (WARRIOR_ANIM.Succeeded())
	{
		Mesh->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}
}

// Called when the game starts or when spawned
void AURSPawn::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			SubSystem->AddMappingContext(DefaultContext, 0);
	}

	// Mesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	// UAnimationAsset* AnimAsset = LoadObject<UAnimationAsset>(nullptr, TEXT("/Game/Resource/Chapter5/WarriorRun.WarriorRun"));
	// if (AnimAsset != nullptr)
	// {
	// 	Mesh->PlayAnimation(AnimAsset, true);
	// }

	
}

// Called every frame
void AURSPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AURSPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UNREALSTUDY_SIMPLE(Warning);
}

void AURSPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	UNREALSTUDY_SIMPLE(Warning);
}



// Called to bind functionality to input
void AURSPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &AURSPawn::Move);
	}
}

void AURSPawn::Move(const FInputActionValue& Value)
{
	const FVector2D movement = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), movement.X);
	AddMovementInput(GetActorRightVector(), movement.Y);
}


