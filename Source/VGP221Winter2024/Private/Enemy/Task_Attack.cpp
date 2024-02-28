// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Task_Attack.h"

EBTNodeResult::Type UTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Attacking Player"));

	// Method 1:
	AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName("Player Target")));

	// Method 2:
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(PlayerPawn);

	if (!PlayerCharacter) return EBTNodeResult::Failed;

	float DamageAmount = 1.0f;
	AEnemyAIController* AIOwner = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	if (!AIOwner) return EBTNodeResult::Failed;

	// Take Damage
	PlayerCharacter->TakeDamage(DamageAmount, FDamageEvent(), AIOwner, AIOwner->GetPawn());

	// Apply Damage
	//UGameplayStatics::ApplyDamage(PlayerCharacter, DamageAmount, AIOwner, AIOwner->GetPawn(), UDamageType::StaticClass());

	return EBTNodeResult::Succeeded;
}
