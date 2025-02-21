// HS

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "WarriorHeroController.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API AWarriorHeroController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	AWarriorHeroController();

	// IGenericTeamAgentInterface
	virtual FGenericTeamId GetGenericTeamId() const override;
	// IGenericTeamAgentInterface

private:
	FGenericTeamId HeroTeamId;
};
