// Shoot Them Up Game, All Rights Reserved.


#include "Components/STURespawnComponent.h"
#include "STUGameModeBase.h"
USTURespawnComponent::USTURespawnComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USTURespawnComponent::Respawn(int32 RespawnTime)
{
    if (!GetWorld())return;

	RespawnConutDown=RespawnTime;
    GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle,this,&USTURespawnComponent::RespawnTimerUpdate,1.0f,true);
}

bool USTURespawnComponent::IsRespawnInProgress()
{
    return GetWorld() && GetWorld()->GetTimerManager().IsTimerActive(RespawnTimerHandle);
}

void USTURespawnComponent::RespawnTimerUpdate()
{
    if (--RespawnConutDown==0)
    {
        if (!GetWorld())return;
        GetWorld()->GetTimerManager().ClearTimer(RespawnTimerHandle);

        const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
        if (!GameMode)return;

        GameMode->RespawnRequest(Cast<AController>(GetOwner()));
    }
}


