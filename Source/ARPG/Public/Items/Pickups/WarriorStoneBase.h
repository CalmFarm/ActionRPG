// HS

#pragma once

#include "CoreMinimal.h"
#include "Items/Pickups/WarriorPickUpBase.h"
#include "WarriorStoneBase.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API AWarriorStoneBase : public AWarriorPickUpBase
{
	GENERATED_BODY()

protected:
	virtual void OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
