// HS

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

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
	
protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

private:
#pragma region components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

#pragma endregion

#pragma region inputs
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterData", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

#pragma endregion
};