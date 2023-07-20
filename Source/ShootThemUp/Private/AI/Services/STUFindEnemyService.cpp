// Shoot Them Up Game, All Rights Reserved.


#include "AI/Services/STUFindEnemyService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include"STUUtils.h"
#include "Components/STUAIPerceptionComponent.h"

USTUFindEnemyService::USTUFindEnemyService()
{
    NodeName = "FindEnemy";
}

void USTUFindEnemyService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    UE_LOG(LogTemp, Display, TEXT("fidn enemy"));
    const auto Blackbord = OwnerComp.GetBlackboardComponent();
    if (Blackbord)
    {
        const auto Controller = OwnerComp.GetAIOwner();
        const auto PerceptionComponent = STUUtils::GetSTUPlayerComponent<USTUAIPerceptionComponent>(Controller);
        if (PerceptionComponent)
        {
        
        Blackbord->SetValueAsObject(EnemyActorKey.SelectedKeyName, PerceptionComponent->GetClosesEnemy());
        }
    }
    Super::TickNode(OwnerComp,NodeMemory,DeltaSeconds);
}
