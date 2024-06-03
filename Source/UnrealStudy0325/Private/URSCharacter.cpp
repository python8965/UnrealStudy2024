// Fill out your copyright notice in the Description page of Project Settings.


#include "URSCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "URSAnimInstance.h"
#include "DrawDebugHelpers.h"
#include "URSPlayerController.h"
#include "Engine/DamageEvents.h"

// Sets default values
AURSCharacter::AURSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	Camera->SetFieldOfView(100.0);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));

	if (SK_CARDBOARD.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(TEXT("/Game/Resource/Chapter5/AnimBP_Warrior.AnimBP_Warrior_C"));
	if (WARRIOR_ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> DEFAULT_CONTEXT(TEXT("/Game/UEStudy/Input/URS_IMC.URS_IMC"));
	if (DEFAULT_CONTEXT.Succeeded())
	{
		DefaultContext = DEFAULT_CONTEXT.Object;
		UNREALSTUDY_SIMPLE(Warning);
	}

	

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_MOVEMENT(TEXT("/Game/UEStudy/Input/Actions/IA_Move.IA_Move"));
	if (IA_MOVEMENT.Succeeded())
		MovementAction = IA_MOVEMENT.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_LOOK(TEXT("/Game/UEStudy/Input/Actions/IA_Look.IA_Look"));
	if (IA_LOOK.Succeeded())
		LookAction = IA_LOOK.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_VIEWCHANGE(TEXT("/Game/UEStudy/Input/Actions/IA_ViewChange.IA_ViewChange"));
	if (IA_VIEWCHANGE.Succeeded())
		ViewChangeAction = IA_VIEWCHANGE.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_JUMP(TEXT("/Game/UEStudy/Input/Actions/IA_Jump.IA_Jump"));
	if (IA_JUMP.Succeeded())
		JumpAction = IA_JUMP.Object;
	
	static ConstructorHelpers::FObjectFinder<UInputAction> IA_ATTACK(TEXT("/Game/UEStudy/Input/Actions/IA_Attack.IA_Attack"));
	if (IA_ATTACK.Succeeded())
		AttackAction = IA_ATTACK.Object;
	
	ArmLengthSpeed = 3.0f;
	ArmRotationSpeed= 10.0f;

	GetCharacterMovement()->JumpZVelocity = 800.0f;

	SetControlMode(CurrentControlMode);

	bIsAttacking = false;

	MaxCombo = 4;
	AttackEndComboState();

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("URSCharacter"));

	AttackRange = 200.0f;
	AttackRadius = 50.0f;
}

// Called when the game starts or when spawned
void AURSCharacter::BeginPlay()
{
	Super::BeginPlay();

	AURSPlayerController* PlayerController = Cast<AURSPlayerController>(Controller);
	if (PlayerController != nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if(Subsystem != nullptr)
		{
			Subsystem->AddMappingContext(DefaultContext, 0);
		} else
		{
			UNREALSTUDY_UELOG(Error, TEXT("SubSystem Null"));
		}
	} else
	{
		UNREALSTUDY_UELOG(Error, TEXT("Controller Cast Failed"));
	}
}

void AURSCharacter::SetControlMode(EControlMode ControlMode)
{
	CurrentControlMode = ControlMode;

	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// SpringArm->TargetArmLength = 450.0f;
		// SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
		ArmLengthTo = 450.0f;
		
		SpringArm->bUsePawnControlRotation = true;

		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;

		SpringArm->bDoCollisionTest = true;
		bUseControllerRotationYaw = false;

		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		break;
	case EControlMode::LostArk:
		// SpringArm->TargetArmLength = 800.0f;
		// SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
		// ArmLengthTo = 800.0f;
		ArmRotationTo = FRotator(-45.0f, 0.0f,0.0f);
		SpringArm->bUsePawnControlRotation = false;

		SpringArm->bInheritPitch = false;
		SpringArm->bInheritRoll = false;
		SpringArm->bInheritYaw = false;

		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bOrientRotationToMovement = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;
	default:
		break;
	}
}

// Called every frame
void AURSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmLengthSpeed);
	
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		break;
	case EControlMode::LostArk:
		SpringArm->SetRelativeRotation(FMath::RInterpTo(SpringArm->GetRelativeRotation(), ArmRotationTo, DeltaTime, ArmRotationSpeed));
		if (DirectionToMove.SizeSquared() > 0.0f)
		{
			GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());

			AddMovementInput(DirectionToMove);
		}
		
		break;
	default:
		break;
	}
}

// Called to bind functionality to input
void AURSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &AURSCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AURSCharacter::Look);
		EnhancedInputComponent->BindAction(ViewChangeAction, ETriggerEvent::Triggered, this, &AURSCharacter::ViewChange);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AURSCharacter::Attack);
	} else
	{
		UNREALSTUDY_UELOG(Error, TEXT("Cannot Cast Playerinputcomponent to enhanced"));
	}
}



void AURSCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D movement = Value.Get<FVector2D>();

	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), movement.Y);
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), movement.X);

		break;
	case EControlMode::LostArk:

		break;
	default:
		break;
	}
}

void AURSCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D movement = Value.Get<FVector2D>();
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddControllerYawInput(movement.X);
		AddControllerPitchInput(movement.Y);
		break;
	case EControlMode::LostArk:

		break;
	default:
		break;
	}
	
}

void AURSCharacter::ViewChange()
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		GetController()->SetControlRotation(GetActorRotation());
		SetControlMode(EControlMode::LostArk);
		break;
	case EControlMode::LostArk:
		GetController()->SetControlRotation(SpringArm->GetRelativeRotation());
		SetControlMode(EControlMode::GTA);
		break;
	default:
		break;
	}
}

void AURSCharacter::Attack()
{
	if (bIsAttacking)
	{
		UNREALSTUDY_CHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 1, MaxCombo));

		if (bCanNextCombo)
		{
			bIsComboInputOn = true;
		}
	} else
	{
		UNREALSTUDY_CHECK(CurrentCombo == 0);
		AttackStartComboState();
		URSAnim->PlayAttackMontage();
		bIsAttacking = true;
		URSAnim->JumpToAttackMontageSection(CurrentCombo);
	}
}

void AURSCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	URSAnim = Cast<UURSAnimInstance>(GetMesh()->GetAnimInstance());

	UNREALSTUDY_CHECK(nullptr != URSAnim);

	URSAnim->OnMontageEnded.AddDynamic(this, &AURSCharacter::OnAttackMontageEnded);

	URSAnim->OnNextAttackCheckDelegate.AddLambda([this]()->void
	{
		bCanNextCombo = false;
		if(bIsComboInputOn)
		{
			AttackStartComboState();
			URSAnim->JumpToAttackMontageSection(CurrentCombo);
		}
	});

	URSAnim->OnAttackHitCheckDelegate.AddUObject(this, &AURSCharacter::AttackCheck);
}

float AURSCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	UNREALSTUDY_UELOG(Warning, TEXT("Actor : %s took Damage : %f"), *GetName(), FinalDamage);


	if (FinalDamage > 0.0f)
	{
		URSAnim->SetDeadAnim();
		SetActorEnableCollision(false);
	}
	
	return FinalDamage;
}

void AURSCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	UNREALSTUDY_CHECK(bIsAttacking);
	UNREALSTUDY_CHECK(CurrentCombo > 0);
	bIsAttacking = false;
	AttackEndComboState();
}

void AURSCharacter::AttackStartComboState()
{
	bCanNextCombo = true;
	bIsComboInputOn = false;
	UNREALSTUDY_CHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 0, MaxCombo - 1));
	CurrentCombo = FMath::Clamp<int32>(CurrentCombo + 1, 1, MaxCombo);
}

void AURSCharacter::AttackEndComboState()
{
	bIsComboInputOn = false;
	bCanNextCombo = false;
	CurrentCombo = 0;
	
}

void AURSCharacter::AttackCheck()
{
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);

	bool bResult = GetWorld()->SweepSingleByChannel(
		HitResult,
		GetActorLocation(),
		GetActorLocation()+GetActorForwardVector() * AttackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(AttackRadius), Params);

#if ENABLE_DRAW_DEBUG
	FVector TraceVec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + TraceVec * 0.5f;
	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;
	float DebugLifeTime = 5.0f;

	DrawDebugCapsule(GetWorld(), Center, HalfHeight, AttackRadius, CapsuleRot, DrawColor, false, DebugLifeTime);
#endif

	if (bResult)
	{
		if (HitResult.GetActor()->IsValidLowLevel())
		{
			UNREALSTUDY_UELOG(Warning, TEXT("Hit Actor Name : %s"), *HitResult.GetActor()->GetName());

			FDamageEvent DamageEvent;
			HitResult.GetActor()->TakeDamage(50.0f, DamageEvent, GetController(), this);
		}
	}
}
