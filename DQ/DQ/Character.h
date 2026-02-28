#pragma once
#include <string>
#include "Spell.h"
class Character
{
public:
	Character(const std::string& name, int hp, int atk, int speed);
   
	int GetHP() const;
	const std::string& GetName() const;
	void TakeDamage(int famage);
	int Attack() const;
	int GetGold() const;
	void AddGold(int amount);
	void AddAttack(int amount);
	void FullHeal();
	int GetMP() const;
	void UseMP(int amount);
	void RecoverMP(int amount);
	void RecoverHP(int amount);

protected:
	std::string name;
	int hp;
	int speed;
	int maxHP;
	int gold;
	int attackPower;
	int mp;
	int maxMP;
};