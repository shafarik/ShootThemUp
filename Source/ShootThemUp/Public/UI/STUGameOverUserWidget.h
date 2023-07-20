// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/STUBaseWidget.h"
#include "STUCoreTypes.h"
#include "STUGameOverUserWidget.generated.h"

class UVerticalBox;
class UButton;
UCLASS()
class SHOOTTHEMUP_API USTUGameOverUserWidget : public USTUBaseWidget
{
    GENERATED_BODY()

public:

protected:
    UPROPERTY(meta = (BindWidget))
    UVerticalBox* PlayerStatBox;

        UPROPERTY(meta = (BindWidget))
        UButton* ResetLevelButton;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerStatRowWidgetClass;

    virtual void NativeOnInitialized()override;

private:
    void OnMatchStateChanged(ESTUMatchState State);
    void UpdatePlayersStat();

    UFUNCTION()
    void OnResetLevel();
};
