#pragma once

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
	void Draw();

private:
	BattleState state;
};