#include "SaveManager.h"
#include <fstream>

void SaveManager::Save(Character* player)
{
	std::ofstream file("Save.dat");

	file << player->GetHP() << std::endl;
	file << player->GetGold() << std::endl;

	file.close();
}

void SaveManager::Load(Character* player)
{
	std::ifstream file("save.dat");

	int hp;
	int gold;
	
	file >> hp;
	file >> gold;

	player->FullHeal();
	player->AddGold(gold - player->GetGold());

	file.close();
}