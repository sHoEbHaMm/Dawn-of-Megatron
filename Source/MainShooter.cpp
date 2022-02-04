// Fill out your copyright notice in the Description page of Project Settings.


#include "MainShooter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "TPS_ShooterGameModeBase.h"
#include "Gun.h"

// Sets default values
AMainShooter::AMainShooter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Health = MaxHealth;
}

// Called when the game starts or when spawned
void AMainShooter::BeginPlay()
{
	Super::BeginPlay();
	
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);
}

// Called every frame
void AMainShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainShooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMainShooter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMainShooter::MoveRight);
	//PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMainShooter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &AMainShooter::Shoot);
}

void AMainShooter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

/*void AMainShooter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}*/

void AMainShooter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

void AMainShooter::LookRight(float Value)
{

}

void AMainShooter::Shoot()
{
	Gun->PullTrigger();
}

float AMainShooter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;

	if (IsDead())
	{
		ATPS_ShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ATPS_ShooterGameModeBase>();

		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}

		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	}

	return DamageToApply;
}

bool AMainShooter::IsDead() const
{
	return Health <= 0;
}

float AMainShooter::GetHealth() const
{
	return Health / MaxHealth;
}