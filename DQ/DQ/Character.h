#pragma once
#include <string>

class Character
{
public:
	Character(const std::string& name, int hp, int atk);
   
	int GetHP() const;
	const std::string& GetName() const;

	void TakeDamage(int famage);
	int Attack() const;

protected:
	std::string name;
	int hp;
	int attack;
};