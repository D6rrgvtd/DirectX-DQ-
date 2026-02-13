#pragma once
#include <string>

class Character
{
public:
	Character(const std::string& name, int hp, int atk, int agi);
   
	int GetHP() const;
	int GetAGI() const;
	const std::string& GetName() const;

	void TakeDamage(int famage);
	int Attack() const;

protected:
	std::string name;
	int hp;
	int attack;
	int agility;
};