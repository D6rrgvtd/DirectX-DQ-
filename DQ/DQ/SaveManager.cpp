#include "SaveManager.h"
#include <fstream>

void SaveManager::Save(Character* player)
{
	std::ofstream file("Save.dat");

	file << player->GetHP() << std::endl;
	file << player->GetMP() << std::endl;
	file << player->HaveGold() << std::endl;
	file << player->GetExp() << std::endl;
	file << player->Getdefence() << std::endl;

	file.close();
}

void SaveManager::Load(Character* player)
{
	std::ifstream file("save.dat");

	int hp;
	int mp;
	int gold;
	int exp;
	int def;
	
	file >> hp;
	file >> mp;
	file >> gold;
	file >> exp;
	file >> def;

	player->SetHP(hp);
	player->SetMP(mp);
	player->SetGold(gold);
	player->SetExp(exp);
	player->SetDef(def);

	file.close();
}