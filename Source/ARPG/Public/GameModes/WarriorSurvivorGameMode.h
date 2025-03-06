// HS

#pragma once

#include "CoreMinimal.h"
#include "GameModes/WarriorBaseGameMode.h"
#include "WarriorSurvivorGameMode.generated.h"

class AWarriorEnemyCharacter;

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

USTRUCT(BlueprintType)
struct FWarriorEnemySpawnerInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<AWarriorEnemyCharacter> SoftEnemyClassToSpawn;

	UPROPERTY(EditAnywhere)
	int32 MinPerSpawn = 1;

	UPROPERTY(EditAnywhere)
	int32 MaxPerSpawn = 3;
};

USTRUCT(BlueprintType)
struct FWarriorEnemySpawnerTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FWarriorEnemySpawnerInfo> EnemyWaveSpawnerDefinitions;

	UPROPERTY(EditAnywhere)
	int32 TotalEnemyToSpawnThisWave = 1;
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
	bool HasFinishedAllWaves() const;
	void PreLoadNextWaveEnemies();
	FWarriorEnemySpawnerTableRow* GetCurrentWaveSpawnerTableRow() const;
	int32 TrySpawnWaveEnemies();
	bool ShouldKeepSpawnEnemies() const;

	UFUNCTION()
	void OnEnemyDestroyed(AActor* DestroyedActor);
	
	UPROPERTY()
	EWarriorSurvivorGameModeState CurrentSurvivorGameModeState;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FOnSurvivorGameModeStateChanged OnSurvivorGameModeStateChanged;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WaveDefinition", meta=(AllowPrivateAccess = "true"))
	UDataTable* EnemyWaveSpawnerDataTable;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="WaveDefinition", meta=(AllowPrivateAccess = "true"))
	int32 TotalWavesToSpawn;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="WaveDefinition", meta=(AllowPrivateAccess = "true"))
	int32 CurrentWaveCount = 1;

	UPROPERTY()
	int32 CurrentSpawnedEnemiesCounter = 0;

	UPROPERTY()
	int32 TotalSpawnedEnemiesThisWaveCounter = 0;

	UPROPERTY()
	TArray<AActor*> TargetPointsArray;

	UPROPERTY()
	float TimePassedSinceStart = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WaveDefinition", meta=(AllowPrivateAccess = "true"))
	float SpawnNewWaveWaitTime = 5.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WaveDefinition", meta=(AllowPrivateAccess = "true"))
	float SpawnEnemiesDelayTime = 2.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WaveDefinition", meta=(AllowPrivateAccess = "true"))
	float WaveCompletedWaitTime = 5.f;

	UPROPERTY()
	TMap< TSoftClassPtr <AWarriorEnemyCharacter>, UClass*>  PreLoadedEnemyClassMap;
};