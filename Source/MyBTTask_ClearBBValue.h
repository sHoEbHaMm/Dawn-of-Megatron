// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_ClearBBValue.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SHOOTER_API UMyBTTask_ClearBBValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UMyBTTask_ClearBBValue();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
