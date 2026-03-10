#pragma once
#include <string>
#include "Spell.h"
#include <iostream>
class Character
{
public:
	Character(const std::string& name, int hp, int atk, int speed,int keke,int maey);
   
	int GetHP() const;
	const std::string& GetName() const;
	void TakeDamage(int famage);
	int Attack() const;
	int Getdefence()const;
	int HaveGold() const;
	int GetExp() const;
	int GetGold() const;
	void AddGold(int amount);
	void AddAttack(int amount);
	void AddExp(int amount);
	void LevelUp();
	void FullHeal();
	int GetMP() const;
	void UseMP(int amount);
	void RecoverMP(int amount);
	void RecoverHP(int amount);
	void SetHP(int value);
	void SetMP(int value);
	void SetGold(int value);
	void SetExp(int value);


protected:
	std::string name;
	int hp;
	int speed;
	int maxHP;
	int gold;
	int maney;
	int attackPower;
	int defense;
	int mp;
	int maxMP;
	int level;
	int exp;
	int keikentu;
	int nextExp;
};