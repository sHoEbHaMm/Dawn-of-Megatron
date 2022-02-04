// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAll_GameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "MainShooterAIController.h"

void AKillEmAll_GameModeBase::PawnKilled(APawn* KilledPawn)
{
	Super::PawnKilled(KilledPawn);

	APlayerController* PlayerController = Cast <APlayerController>(KilledPawn->GetController());
	if (PlayerController != nullptr)
	{
		EndGame(false);
	}

	for (AMainShooterAIController* AIController : TActorRange<AMainShooterAIController>(GetWorld()))
	{
		if (!AIController->IsDead())
		{
			return;
		}
	}

	EndGame(true);
}

void AKillEmAll_GameModeBase::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}