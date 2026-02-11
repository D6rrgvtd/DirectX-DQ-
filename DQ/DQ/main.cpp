#include "BattleScene.h"

int main()
{
	BattleScene battle;

	battle.Init();

	while (true)
	{
		battle.Update();
		battle.Draw(nullptr);
		break;
	}

	return 0;
}