// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTaskNode_Shoot.h"
#include "AIController.h"
#include "MainShooter.h"

UMyBTTaskNode_Shoot::UMyBTTaskNode_Shoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UMyBTTaskNode_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner()->GetPawn() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AMainShooter* MainShooter = Cast<AMainShooter>(OwnerComp.GetAIOwner()->GetPawn());
	if (MainShooter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	MainShooter->Shoot();

	return EBTNodeResult::Succeeded;
}