// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Task_GetRandomLocation.h"

EBTNodeResult::Type UTask_GetRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>((UGameplayStatics::GetPlayerPawn(GetWorld(), 0)));

	// 1.Try to get random point on nav mesh
	// 2. If succesful see the Random Patrol Location to that value
	// 3. If failed return failed
	if (NavArea) {
		NavArea->K2_GetRandomLocationInNavigableRadius(GetWorld(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(), RandomLocation, 2000.0f);
	}
	else {
		return EBTNodeResult::Failed;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("Random Patrol Location"), RandomLocation);

	return EBTNodeResult::Succeeded;
}
