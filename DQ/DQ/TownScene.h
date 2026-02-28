#pragma once
#include "Scene.h"
#include "Character.h"
class TownScene :public Scene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
	bool IsFinished()const override;
	TownScene(Character* p);

private:
	bool isFinished;
	Character* player;
};