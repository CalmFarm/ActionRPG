// HS


#include "GameModes/WarriorSurvivorGameMode.h"

void AWarriorSurvivorGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AWarriorSurvivorGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AWarriorSurvivorGameMode::SetCurrentSurvivorGameModeState(EWarriorSurvivorGameModeState InState)
{
	CurrentSurvivorGameModeState = InState;

	OnSurvivorGameModeStateChanged.Broadcast(CurrentSurvivorGameModeState);
}
