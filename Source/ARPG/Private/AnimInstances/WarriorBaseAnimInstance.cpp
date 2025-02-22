// HS


#include "AnimInstances/WarriorBaseAnimInstance.h"

#include "WarriorFunctionLibrary.h"

bool UWarriorBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck)
{
	if (APawn* OwningPawn = TryGetPawnOwner())
	{
		return UWarriorFunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
	}
	return false;
}
