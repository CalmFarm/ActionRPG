// HS

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class ARPG_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	AWarriorEnemyCharacter();

protected:
	// APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// APawn Interface
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UEnemyCombatComponent* EnemyCombatComponent;

private:
	void InitEnemyStartUpData();
public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const {return EnemyCombatComponent;}
};
