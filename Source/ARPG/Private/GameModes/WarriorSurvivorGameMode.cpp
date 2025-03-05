// HS


#include "GameModes/WarriorSurvivorGameMode.h"

void AWarriorSurvivorGameMode::BeginPlay()
{
	Super::BeginPlay();

	checkf(EnemyWaveSpawnerDataTable, TEXT("Forgot to assign a valid data table in survivor game mode blueprint"));

	SetCurrentSurvivorGameModeState(EWarriorSurvivorGameModeState::WaitSpawnNewWave);

	TotalWavesToSpawn = EnemyWaveSpawnerDataTable->GetRowNames().Num();
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
	return CurrentWaveCount >= TotalWavesToSpawn;
}

