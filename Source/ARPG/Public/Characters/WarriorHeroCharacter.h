// HS

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

class UHeroPawnUIComponent;
struct FGameplayTag;
class UHeroCombatComponent;
struct FInputActionValue;
class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class ARPG_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()
public:
	AWarriorHeroCharacter();

	// IPawnCombatInterface
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	// IPawnCombatInterface

	// IPawnUIInterface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	virtual UHeroPawnUIComponent* GetHeroUIComponent() const override;
	// IPawnUIInterface
	
protected:
	// APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// APawn Interface
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

private:
#pragma region components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat", meta = (AllowPrivateAccess = "true"))
	UHeroCombatComponent* HeroCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI", meta = (AllowPrivateAccess = "true"))
	UHeroPawnUIComponent* HeroUIComponent;
#pragma endregion

#pragma region inputs
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterData", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);

#pragma endregion

public:
	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }
};