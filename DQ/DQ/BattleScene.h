#pragma once
#include <d3d12.h>
enum class BattleState
{
	start,
	commandSelect
};

class BattleScene
{
public:
	void Init();
	void Update();
	void Draw(ID3D12GraphicsCommandList* cmdList);

private:
	BattleState state;
};