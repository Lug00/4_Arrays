#include "Character.h"

Character::Character()
{
	karma = 0;
	//myweapons = GenericArray<Weapon>();


}

Character::Character(const char* _name)
{
	karma = 0;
	//myweapons = GenericArray<Weapon>();
	name = _name;
}

void Character::SetType(EChartype _type)
{
	CharType = _type;
}

const char* Character::GetType()
{
	if (CharType == EChartype::npc) return "NPC";
	else if (CharType == EChartype::player) return "Player";
}