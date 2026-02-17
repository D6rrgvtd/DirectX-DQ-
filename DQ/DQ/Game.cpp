#include "Game.h"
#include "FieldScene.h"
#include "BattleScene.h"

void Game::Run()
{
	currentScene = new FieldScene();
	currentScene->Init();

	while (true)
	{
		currentScene->Update();
		currentScene->Draw();

		if (currentScene->IsFinished())
		{
			//フィールドなら戦闘へ
			if (dynamic_cast<FieldScene*>(currentScene))
			{
				delete currentScene;
				currentScene = new BattleScene();
				currentScene->Init();
			}
			else
			{
				delete currentScene;
				currentScene = new FieldScene();
				currentScene->Init();
			}
		}
	}
}