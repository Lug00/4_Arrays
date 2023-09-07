#pragma once
#include "Entity.h"
//#include "GenericArray.h"
#include "Weapon.h"

class Character :public Entity
{
public:

	enum EChartype {
		player, npc
	} CharType = EChartype::npc;

	int karma;

	//GenericArray<Weapon> myweapons;
	Character();
	Character(const char* _name);

	void SetType(EChartype _type);
	const char* GetType();

};