#include "BattleScene.h"

void BattleScene::Init()
{
	state = BattleState::start;
}

void BattleScene::Update()
{
	switch (state)
	{
	case BattleState::start:
		//í“¬ŠJn‰‰o
		state = BattleState::commandSelect;
		break;
	case BattleState::commandSelect:
		break;
	
	}
}

void BattleScene::Draw(ID3D12GraphicsCommandList* cmdList)
{
	
}