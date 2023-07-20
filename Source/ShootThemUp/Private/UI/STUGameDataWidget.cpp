// Shoot Them Up Game, All Rights Reserved.

#include "UI/STUGameDataWidget.h"
#include "Player/STUPlayerState.h"
#include "STUGameModeBase.h"



int32 USTUGameDataWidget::GetCurrentRoundNum() const
{
    const auto GameMode = GetSTUGameMode();
    return GameMode ? GameMode->GetCurrentRoundNum():0;
}

int32 USTUGameDataWidget::GetTotalRoundsNum() const
{
    const auto GameMode = GetSTUGameMode();
    return GameMode ? GameMode->GetGameData().RoundsNum:0;
}

int32 USTUGameDataWidget::GetRoundSecondsRemaining() const
{
    const auto GameMode = GetSTUGameMode();
    return GameMode ? GameMode->GetRoundSecondsRemaining():0;
}

ASTUGameModeBase* USTUGameDataWidget::GetSTUGameMode() const
{
    return GetWorld() ? Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
}

ASTUPlayerState* USTUGameDataWidget::GetSTUPlayerState() const
{
    return GetOwningPlayer() ? Cast<ASTUPlayerState>(GetOwningPlayer()->PlayerState) : nullptr;
}
