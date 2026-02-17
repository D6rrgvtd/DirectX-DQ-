#pragma once
#include <iostream>
#include "Character.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include"Scene.h"

enum class BattleState
{
	start,
	commandSelect,
	end
};

class BattleScene : public Scene
{
public:
	BattleScene();
	~BattleScene();
	void Init() override;
	void Update() override;
	void Draw() override;
	bool IsFinished() const override;
	
	
private:
	BattleState state;
	bool isFinished;
	Character* player;
	std::vector<Character*> enemies;
};