// HS

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtendsionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARPG_API UPawnExtendsionComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// 템플릿 함수: 주어진 타입 T가 소유하는 Pawn을 반환
	template <class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' Template Parameter get GetPawn must be convertible to a Pawn");
		return CastChecked<T>(GetOwner());
	}
	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	template <class T>
	T* GetOwningController()
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerController>::Value, "'T' Template Parameter get GetPlayerController must be convertible to a PlayerController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}
};
