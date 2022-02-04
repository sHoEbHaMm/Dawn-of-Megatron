// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TPS_ShooterGameModeBase.h"
#include "KillEmAll_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SHOOTER_API AKillEmAll_GameModeBase : public ATPS_ShooterGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void PawnKilled(APawn* KilledPawn) override;

private:
	void EndGame(bool bIsPlayerWinner);
};
