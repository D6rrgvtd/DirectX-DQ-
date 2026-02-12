#pragma once
#include <iostream>
#include "Character.h"
enum class BattleState
{
	start,
	commandSelect,
	end
};

class BattleScene
{
public:
	void Init();
	void Update();
	
private:
	BattleState state;

	Character* player;
	Character* enemy;
};