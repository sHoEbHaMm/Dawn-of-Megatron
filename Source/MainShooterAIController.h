// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MainShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SHOOTER_API AMainShooterAIController : public AAIController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
	//float AcceptanceRadius = 200.f;

public:
	bool IsDead() const;
};
