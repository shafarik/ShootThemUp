// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUCoreTypes.h"
#include "STUHealthComponent.generated.h"

class UCameraShakeBase;
class UPhysicalMaterial;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USTUHealthComponent();

    float GetHealth() const
    {
        return Health;
    }

    bool PickupHeal(int32 HealthAmount);

    UFUNCTION(BlueprintCallable, Category = "Health")
    bool IsDead() const
    {
        return FMath::IsNearlyZero(Health);
    }
    UFUNCTION(BlueprintCallable, Category = "Health")
    float GetHealthPrecent() const
    {
        return Health / MaxHealth;
    }

    FOnDeath OnDeath;
    FOnHealthChanged OnHealthChenged;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal")
    bool AutoHeal = true;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "AutoHeal"))
    float HealUpdateTime = 0.3f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "AutoHeal"))
    float HealDelay = 3.0f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "AutoHeal"))
    float HealModifier = 1.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    TSubclassOf<UCameraShakeBase> CameraShake;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
    TMap<UPhysicalMaterial*, float> DamageModifiers;

protected:
    virtual void BeginPlay() override;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "0.0", ClampMax = "1000"))
    float MaxHealth = 100.0f;

    UFUNCTION()
    void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy,
                         AActor* DamageCauser);

private:
    float Health = 0.0f;
    FTimerHandle HealTimeHandle;

    void HealUpdate();
    void SetHealth(float NewHealth);
    void PlayCameraShake();

    void Killed(AController* KillerController);
    UFUNCTION()
    void OnTakePointDamage(AActor* DamagedActor, float Damage, class AController* InstigatedBy, FVector HitLocation,
                           class UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection,
                           const class UDamageType* DamageType, AActor* DamageCauser);

    UFUNCTION()
    void OnTakeRadialDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType,
                            FVector Origin, FHitResult HitInfo, class AController* InstigatedBy, AActor* DamageCauser);

    void ApplyDamage(float Damage, AController* InstigatedBy);
    float GetPointDamageModifier(AActor* DamagedActor,const FName& BoneName);

    void ReportDamageEvent(float Damage, AController* InstigatedBy);
};
