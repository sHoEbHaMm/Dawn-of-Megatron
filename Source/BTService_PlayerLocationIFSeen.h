// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlayerLocationIFSeen.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SHOOTER_API UBTService_PlayerLocationIFSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()

	UBTService_PlayerLocationIFSeen();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
