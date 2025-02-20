// HS

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtendsionComponent.h"
#include "PawnUIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPercentChangeDelegate, float, NewPercent);

/**
 * 
 */
UCLASS()
class ARPG_API UPawnUIComponent : public UPawnExtendsionComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnPercentChangeDelegate OnCurrentHealthChanged;
};
