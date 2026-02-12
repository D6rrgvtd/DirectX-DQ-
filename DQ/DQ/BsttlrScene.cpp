#include "BattleScene.h"

using namespace std;

void BattleScene::Init()
{
	state = BattleState::start;

	player = new Character("プレイヤー", 30, 5);
	enemy = new Character("スライム", 8, 3);
}

void BattleScene::Update()
{
	switch (state)
	{
	case BattleState::start:
		//戦闘開始演出
		state = BattleState::commandSelect;
		break;
	case BattleState::commandSelect:
		break;
	
	}
}
