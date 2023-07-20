// Shoot Them Up Game, All Rights Reserved.

#include "AI/Decorators/STUClipsAmountDecorator.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUWeaponComponent.h"
USTUClipsAmountDecorator::USTUClipsAmountDecorator()
{
    NodeName = "Need Ammo";
}

bool USTUClipsAmountDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller)
        return false;

    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());
    if (!WeaponComponent)
        return false;

    return WeaponComponent->NeedAmmo(WeaponType);
}
