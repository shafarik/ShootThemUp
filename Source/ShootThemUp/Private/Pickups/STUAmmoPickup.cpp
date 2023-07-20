// Shoot Them Up Game, All Rights Reserved.

#include "Pickups/STUAmmoPickup.h"
#include "Components/STUWeaponComponent.h"
#include "Components/STUHealthComponent.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);

bool ASTUAmmoPickup::GivePickupTo(APawn* PlayerPawn)
{
    const auto HealthComponnent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
    if (!HealthComponnent||HealthComponnent->IsDead())return false;

    const auto WeaponComponnent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(PlayerPawn);
    if (!WeaponComponnent)return false;


    return WeaponComponnent->TryToAddAmmo(WeaponType,ClipsAmount);
}