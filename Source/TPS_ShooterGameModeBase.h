// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPS_ShooterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SHOOTER_API ATPS_ShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* KilledPawn);
};
