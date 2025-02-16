// HS

#pragma once

#include "WarriorStructTypes.generated.h"

class UWarriorHeroLinkedAnimInstance;

USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorHeroLinkedAnimInstance> WeaponAnimLayerToLink;
};