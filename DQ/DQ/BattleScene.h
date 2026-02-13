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
	BattleScene();
	~BattleScene();
	void Init();
	void Update();
	bool IsFinished() const;
	
	
private:
	BattleState state;
	bool isFinished;
	Character* player;
	Character* enemy;
};