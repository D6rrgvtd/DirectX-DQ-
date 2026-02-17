#pragma once
#include "Scene.h"

class Game
{
public:
	void Run();

private:
	Scene* currentScene;
};