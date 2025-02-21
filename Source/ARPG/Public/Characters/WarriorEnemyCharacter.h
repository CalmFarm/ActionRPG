// HS

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

class UWidgetComponent;
class UEnemyPawnUIComponent;
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

	// IPawnCombatInterface
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	// IPawnCombatInterface

	// IPawnUIInterface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	virtual UEnemyPawnUIComponent* GetEnemyUIComponent () const override;
	// IPawnUIInterface

protected:

	virtual void BeginPlay() override;
	
	// APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// APawn Interface
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UEnemyCombatComponent* EnemyCombatComponent;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "UI")
	UEnemyPawnUIComponent* EnemyUIComponent;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "UI")
	UWidgetComponent* EnemyHealthWidgetComponent;

private:
	void InitEnemyStartUpData();
public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const {return EnemyCombatComponent;}
};
