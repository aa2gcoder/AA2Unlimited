#include "Globals.h"

#include "External\ExternalVariables\AAPlay\GameGlobals.h"

namespace AAPlay {



CharInstData g_characters[25];


void InitOnLoad() {
	for(int i = 0; i < 25; i++) {
		g_characters[i].Reset();
	}

	//initialize characters
	ExtClass::CharacterStruct** start = ExtVars::AAPlay::ClassMembersArray();
	ExtClass::CharacterStruct** end = ExtVars::AAPlay::ClassMembersArray();
	for(start; start != end; start++) {
		ExtClass::CharacterStruct* it = *start;

		int seat = it->m_seat;
		g_characters[seat].m_char = it;
		g_characters[seat].m_cardData.FromFileBuffer((char*)it->m_charData->m_pngBuffer,it->m_charData->m_pngBufferSize);
		
	}
}

void InitTransferedCharacter(ExtClass::CharacterStruct* character) {
	int seat = character->m_seat;
	g_characters[seat].m_char = character;
	g_characters[seat].m_cardData.FromFileBuffer((char*)character->m_charData->m_pngBuffer,character->m_charData->m_pngBufferSize);
}
void RemoveTransferedCharacter(ExtClass::CharacterStruct* character) {
	int seat = character->m_seat;
	g_characters[seat].Reset();
}



}