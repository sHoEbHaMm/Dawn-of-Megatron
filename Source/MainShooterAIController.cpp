// Fill out your copyright notice in the Description page of Project Settings.


#include "MainShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MainShooter.h"

void AMainShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());

		GetBlackboardComponent()->SetValueAsVector(TEXT("SelfLocation"), GetPawn()->GetActorLocation());
	}
}

void AMainShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AMainShooterAIController::IsDead() const
{
	AMainShooter* ControlledShooter = Cast<AMainShooter>(GetPawn());
	if (ControlledShooter != nullptr)
	{
		return ControlledShooter->IsDead();
	}
	
	return true;
}