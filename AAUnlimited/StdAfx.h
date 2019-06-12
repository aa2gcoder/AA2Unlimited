#pragma once

#define _USE_MATH_DEFINES

#include <windows.h>
#include <Windowsx.h>
#include <d3d9.h>
#include <gdiplus.h>

#include <limits>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#include <sstream>
#include <fstream>
#include <iostream>
#include <limits>

#include <initializer_list>
#include <map>
#include <queue>
#include <array>
#include <deque>
#include <set>
#include <stack>
#include <vector>
#include <string>

#include "lua.hpp"
#include "Script/glua.h"
#include "Script/ScriptLua.h"

#include "defs.h"
#include "External/AddressRule.h"
#include "External/ExternalClasses/Animation.h"
#include "External/ExternalClasses/Bone.h"
#include "External/ExternalClasses/CharacterActivity.h"
#include "External/ExternalClasses/CharacterData.h"
#include "External/ExternalClasses/CharacterNpcAiData.h"
#include "External/ExternalClasses/CharacterNpcReactData.h"
#include "External/ExternalClasses/CharacterRelation.h"
#include "External/ExternalClasses/CharacterStruct.h"
#include "External/ExternalClasses/ConversationStruct.h"
#include "External/ExternalClasses/Frame.h"
#include "External/ExternalClasses/Camera.h"
#include "External/ExternalClasses/HClasses/HGUIButton.h"
#include "External/ExternalClasses/HClasses/HInfo.h"
#include "External/ExternalClasses/HClasses/HParticipant.h"
#include "External/ExternalClasses/HClasses/HPosButtonList.h"
#include "External/ExternalClasses/HClasses/HPosData.h"
#include "External/ExternalClasses/CharacterStatus.h"
#include "External/ExternalClasses/NpcStatus.h"
#include "External/ExternalClasses/NpcData.h"
#include "External/ExternalClasses/IllusionArray.h"
#include "External/ExternalClasses/IllusionList.h"
#include "External/ExternalClasses/Keyframe.h"
#include "External/ExternalClasses/LoverData.h"
#include "External/ExternalClasses/TextureStruct.h"
#include "External/ExternalClasses/TimeData.h"
#include "External/ExternalClasses/XXFile.h"
#include "External/ExternalClasses/XXFileFace.h"
#include "External/ExternalClasses/Material.h"
#include "External/ExternalClasses/Light.h"
#include "External/ExternalClasses.h"
#include "External/ExternalVariables/AAEdit/CardData.h"
#include "External/ExternalVariables/AAEdit/RefreshTable.h"
#include "External/ExternalVariables/AAEdit/WindowData.h"
#include "External/ExternalVariables/AAPlay/GameGlobals.h"
#include "External/ExternalVariables.h"
#include "Files/ClothFile.h"
#include "Files/Config.h"
#include "Files/Logger.h"
#include "Files/ModuleFile.h"
#include "Files/PP2.h"
#include "Files/PPeX.h"
#include "Files/XXFile.h"
#include "Functions/AAEdit/Globals.h"
#include "Functions/AAEdit/UnlimitedDialog.h"
#include "Functions/AAEdit/UnlimitedDialogParts/Triggers.h"
#include "Functions/AAPlay/Facecam.h"
#include "Functions/AAPlay/GameState.h"
#include "Functions/AAPlay/Globals.h"
#include "Functions/AAPlay/HAi.h"
#include "Functions/AAPlay/HAis/BaseAi.h"
#include "Functions/AAPlay/HAis/ForceAi.h"
#include "Functions/AAPlay/HButtonMove.h"
#include "Functions/AAPlay/Poser.h"
#include "Functions/AAPlay/Subs.h"
#include "Functions/AAUCardData.h"
#include "Functions/CharInstData.h"
#include "Functions/OverrideFile.h"
#include "Functions/Serialize.h"
#include "Functions/Shared/Globals.h"
#include "Functions/Shared/Overrides.h"
#include "Functions/Shared/Shadowing.h"
#include "Functions/Shared/Slider.h"
#include "Functions/Shared/SpecialOverrides.h"
#include "Functions/Shared/TriggerEventDistributor.h"
#include "Functions/Shared/Triggers/Actions.h"
#include "Functions/Shared/Triggers/Event.h"
#include "Functions/Shared/Triggers/Expressions.h"
#include "Functions/Shared/Triggers/InfoData.h"
#include "Functions/Shared/Triggers/Module.h"
#include "Functions/Shared/Triggers/NamedConstant.h"
#include "Functions/Shared/Triggers/Thread.h"
#include "Functions/Shared/Triggers/Triggers.h"
#include "Functions/Shared/Triggers/Value.h"
#include "Functions/TextureImage.h"
#include "Functions/XXObjectFile.h"
#include "General/Buffer.h"
#include "General/DrawD3D.h"
#include "General/DirectXStructs.h"
#include "General/IllusionUtil.h"
#include "General/ModuleInfo.h"
#include "General/Util.h"
#include "MemMods/AAEdit/Dialog.h"
#include "MemMods/AAEdit/TanSlotUnlimited.h"
#include "MemMods/AAPlay/Events/CharacterActions.h"
#include "MemMods/AAPlay/Events/ClothingDialog.h"
#include "MemMods/AAPlay/Events/HInjections.h"
#include "MemMods/AAPlay/Events/Loads.h"
#include "MemMods/AAPlay/Events/NpcActions.h"
#include "MemMods/AAPlay/Events/PcActions.h"
#include "MemMods/AAPlay/Events/PcConversation.h"
#include "MemMods/AAPlay/Events/ScreenCapture.h"
#include "MemMods/AAPlay/Events/Time.h"
#include "MemMods/AAPlay/Misc/TanSlotUnlimit.h"
#include "MemMods/Hook.h"
#include "MemMods/MemRightsLock.h"
#include "MemMods/Shared/Events/ArchiveFileOpen.h"
#include "MemMods/Shared/Events/FileDump.h"
#include "MemMods/Shared/Events/FrameManipulationTest.h"
#include "MemMods/Shared/Events/GameTick.h"
#include "MemMods/Shared/Events/HairMeshes.h"
#include "MemMods/Shared/Events/MemAlloc.h"
#include "MemMods/Shared/Events/MeshTexture.h"
#include "MemMods/Shared/Misc/EyeTexture.h"
#include "MemMods/Shared/Misc/FixLocale.h"
#include "Hooks/WinAPI.h"

#include "resource.h"


#pragma comment (lib, "Gdiplus.lib")
