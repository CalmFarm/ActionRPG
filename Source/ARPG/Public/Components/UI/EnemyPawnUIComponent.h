// HS

#pragma once

#include "CoreMinimal.h"
#include "Components/UI/PawnUIComponent.h"
#include "EnemyPawnUIComponent.generated.h"

class UWarriorWidgetBase;
/**
 * 
 */
UCLASS()
class ARPG_API UEnemyPawnUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void RegisterEnemyDrawnWidget(UWarriorWidgetBase* InWidgetToRegister);

	UFUNCTION(BlueprintCallable)
	void RemoveEnemyDrawnWidgetsIfAny();
	
private:
	TArray<UWarriorWidgetBase*> EnemyDrawnWidgets;
};
