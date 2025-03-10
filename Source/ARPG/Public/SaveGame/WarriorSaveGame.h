// HS

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "WarriorTypes/WarriorEnumTypes.h"
#include "WarriorSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API UWarriorSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	EWarriorGameDifficulty SavedCurrentGameDifficulty;
};
