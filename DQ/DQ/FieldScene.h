#pragma once
#include "Scene.h"

class FieldScene : public Scene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
	bool IsFinished() const override;

private:
	int playerX;
	int playerY;
	bool encounter;
};