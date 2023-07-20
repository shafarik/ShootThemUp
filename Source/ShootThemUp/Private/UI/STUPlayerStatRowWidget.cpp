// Shoot Them Up Game, All Rights Reserved.

#include "UI/STUPlayerStatRowWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void USTUPlayerStatRowWidget::SetPLayerName(const FText& Text)
{
    if (!PLayerNameTextBlock)
        return;

    PLayerNameTextBlock->SetText(Text);
}

void USTUPlayerStatRowWidget::SetKills(const FText& Text)
{
    if (!KillsTextBlock)
        return;

    KillsTextBlock->SetText(Text);
}

void USTUPlayerStatRowWidget::SetDeaths(const FText& Text)
{
    if (!DeathsTextBlock)
        return;

    DeathsTextBlock->SetText(Text);
}

void USTUPlayerStatRowWidget::SetTeam(const FText& Text)
{
    if (!TeamTextBlock)
        return;

    TeamTextBlock->SetText(Text);
}

void USTUPlayerStatRowWidget::SetPlayerIndicatorVisibility(bool Visible)
{
    if (!PlayerIndicatorImage)
        return;

    PlayerIndicatorImage->SetVisibility(Visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

void USTUPlayerStatRowWidget::SetTeamColor(const FLinearColor& Color)
{
    if (!TeamImage)return;

    TeamImage->SetColorAndOpacity(Color);
}
