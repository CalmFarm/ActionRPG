// HS

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstance.h"
#include "WarriorHeroLinkedAnimInstance.generated.h"

class UWarriorHeroAnimInstance;
/**
 * 
 */
UCLASS()
class ARPG_API UWarriorHeroLinkedAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UWarriorHeroAnimInstance* GetWarriorHeroAnimInstance() const;
};
