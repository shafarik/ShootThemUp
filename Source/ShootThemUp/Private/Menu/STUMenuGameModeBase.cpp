// Shoot Them Up Game, All Rights Reserved.


#include "Menu/STUMenuGameModeBase.h"
#include "Menu/STUMenuPlayerController.h"
#include "Menu/UI/STUMenuHUD.h"
#include "STUGameInstance.h"

ASTUMenuGameModeBase::ASTUMenuGameModeBase()
{
    PlayerControllerClass = ASTUMenuPlayerController::StaticClass();
    HUDClass = ASTUMenuHUD::StaticClass();
}

void ASTUMenuGameModeBase::BeginPlay()
{
    if (!GetWorld())return;
    const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
    if (STUGameInstance)
    {
        STUGameInstance->GetMasterSoundClass()->Properties.Volume == 0.0f ? STUGameInstance->ToggleVolume() : nullptr; // ya nasral
    }
}
