// HS


#include "GameModes/WarriorSurvivorGameMode.h"

#include "WarriorDebugHelper.h"
#include "Characters/WarriorEnemyCharacter.h"
#include "Engine/AssetManager.h"

void AWarriorSurvivorGameMode::BeginPlay()
{
	Super::BeginPlay();

	checkf(EnemyWaveSpawnerDataTable, TEXT("Forgot to assign a valid data table in survivor game mode blueprint"));

	SetCurrentSurvivorGameModeState(EWarriorSurvivorGameModeState::WaitSpawnNewWave);

	TotalWavesToSpawn = EnemyWaveSpawnerDataTable->GetRowNames().Num();

	PreLoadNextWaveEnemies();
}

void AWarriorSurvivorGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (CurrentSurvivorGameModeState == EWarriorSurvivorGameModeState::WaitSpawnNewWave)
	{
		TimePassedSinceStart += DeltaSeconds;
		
		if (TimePassedSinceStart >= SpawnNewWaveWaitTime)
		{
			TimePassedSinceStart = 0.f;

			SetCurrentSurvivorGameModeState(EWarriorSurvivorGameModeState::SpawningWave);
		}
	}

	if (CurrentSurvivorGameModeState == EWarriorSurvivorGameModeState::SpawningWave)
	{
		TimePassedSinceStart += DeltaSeconds;

		if (TimePassedSinceStart >= SpawnEnemiesDelayTime)
		{
			//TODO : Handle New Spawn Enemy

			TimePassedSinceStart = 0.f;

			SetCurrentSurvivorGameModeState(EWarriorSurvivorGameModeState::InProgress);
		}
	}

	if (CurrentSurvivorGameModeState == EWarriorSurvivorGameModeState::WaveComplete)
	{
		TimePassedSinceStart += DeltaSeconds;

		if (TimePassedSinceStart >= WaveCompletedWaitTime)
		{
			TimePassedSinceStart = 0.f;

			CurrentWaveCount++;

			if (HasFinishedAllWaves())
			{
				SetCurrentSurvivorGameModeState(EWarriorSurvivorGameModeState::AllWavesDone);
			}
			else
			{
				SetCurrentSurvivorGameModeState(EWarriorSurvivorGameModeState::WaitSpawnNewWave);
				PreLoadNextWaveEnemies();
			}
		}
	}
}

void AWarriorSurvivorGameMode::SetCurrentSurvivorGameModeState(EWarriorSurvivorGameModeState InState)
{
	CurrentSurvivorGameModeState = InState;

	OnSurvivorGameModeStateChanged.Broadcast(CurrentSurvivorGameModeState);
}

bool AWarriorSurvivorGameMode::HasFinishedAllWaves() const
{
	return CurrentWaveCount > TotalWavesToSpawn;
}

void AWarriorSurvivorGameMode::PreLoadNextWaveEnemies()
{
	if (HasFinishedAllWaves()) return;

	for (const FWarriorEnemySpawnerInfo& SpawnerInfo : GetCurrentWaveSpawnerTableRow()->EnemyWaveSpawnerDefinitions)
	{
		if (SpawnerInfo.SoftEnemyClassToSpawn.IsNull()) continue;

		UAssetManager::GetStreamableManager().RequestAsyncLoad(
			SpawnerInfo.SoftEnemyClassToSpawn.ToSoftObjectPath(),
			FStreamableDelegate::CreateLambda(
				[SpawnerInfo,this]()
				{
					if (UClass* LoadedEnemyClass = SpawnerInfo.SoftEnemyClassToSpawn.Get())
					{
						PreLoadedEnemyClass.Emplace(SpawnerInfo.SoftEnemyClassToSpawn, LoadedEnemyClass);
						
						Debug::Print(LoadedEnemyClass->GetName() + TEXT("is Loaded"));
					}
				}
			));
	}
}

FWarriorEnemySpawnerTableRow* AWarriorSurvivorGameMode::GetCurrentWaveSpawnerTableRow() const
{
	const FName RowName = FName(TEXT("Wave") + FString::FromInt(CurrentWaveCount));
	
	FWarriorEnemySpawnerTableRow* FoundRow = EnemyWaveSpawnerDataTable->FindRow<FWarriorEnemySpawnerTableRow>(RowName, FString());

	checkf(FoundRow, TEXT("Could not find a valid row under the name %s in the data table"), *RowName.ToString());

	return FoundRow;
}

