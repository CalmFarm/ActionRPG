// HS

#pragma once

#include "NativeGameplayTags.h"

namespace WarriorGameplayTags
{
	// Input Tags
	ARPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	ARPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	ARPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Equip);
	ARPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnEquip);

	// Player Tags
	ARPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	ARPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	ARPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_UnEquip_Axe);
}
