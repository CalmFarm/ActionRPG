// HS

#pragma once

#include "CoreMinimal.h"
#include "GameModes/WarriorBaseGameMode.h"
#include "WarriorSurvivorGameMode.generated.h"

UENUM(BlueprintType)
enum class EWarriorSurvivorGameModeState : uint8
{
	WaitSpawnNewWave,
	SpawningWave,
	InProgress,
	WaveComplete,
	AllWavesDone,
	PlayerDied
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSurvivorGameModeStateChanged, EWarriorSurvivorGameModeState, CurrentState);

/**
 * 
 */
UCLASS()
class ARPG_API AWarriorSurvivorGameMode : public AWarriorBaseGameMode
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	void SetCurrentSurvivorGameModeState(EWarriorSurvivorGameModeState InState);
	
	UPROPERTY()
	EWarriorSurvivorGameModeState CurrentSurvivorGameModeState;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FOnSurvivorGameModeStateChanged OnSurvivorGameModeStateChanged;
};
