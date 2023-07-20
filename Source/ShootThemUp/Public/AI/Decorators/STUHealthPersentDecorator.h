// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "STUHealthPersentDecorator.generated.h"


UCLASS()
class SHOOTTHEMUP_API USTUHealthPersentDecorator : public UBTDecorator
{
	GENERATED_BODY()
	public:
    USTUHealthPersentDecorator();
	protected:
    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		float HealthPersent=0.6f;
};
