#include "FieldScene.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void FieldScene::Init()
{
	playerX = 0;
	playerY = 0;
	encounter = false;

	srand((unsigned int)time(nullptr));
}

void FieldScene::Update()
{
	cout << "WASDで移動:";
	char input;
	cin >> input;

	if (input == 'W') playerY++;
	if (input == 'S') playerY--;
	if (input == 'a') playerX--;
	if (input == 'd') playerX++;

	cout << "現在地: (" << playerX << "," << playerY << ")\n";

	//30%でエンカウント
	if (rand() % 100 < 30)
	{
		encounter = true;
	}
}

void FieldScene::Draw()
{
	//
}

bool FieldScene::IsFinished() const
{
	return encounter;
}