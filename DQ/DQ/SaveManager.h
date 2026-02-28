#pragma once
#include "Character.h"

class SaveManager
{
public:
	static void Save(Character* player);
	static void Load(Character* player);
};
