#include "Character.h"

Character::Character(const std::string&, int hp, int attack, int speed)
{
	this->name = name;
	this->maxHP = hp;
	this->hp = hp;
	this->attackPower = attack;
	this->speed = speed;
	gold = 100;
	maxMP = 10;
	mp = maxMP;

	level = 1;
	exp = 0;
	nextExp = 10;
}


int Character::GetHP() const
{
	return hp;
}

const std::string& Character::GetName() const
{
	return name;
}

void Character::TakeDamage(int damage)
{
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
}

int Character::Attack() const
{
	return attackPower;
}

int Character::GetGold() const
{
	return gold;
}

void Character::AddGold(int amount)
{
	gold += amount;
	if (gold < 0)
		gold = 0;
}

void Character::AddAttack(int amount)
{
	attackPower += amount;
}

void Character::AddExp(int amount)
{
	exp += amount;
	std::cout << amount << "の経験値を獲得\n";

	if (exp >= nextExp)
	{
		LevelUp();
	}
}

void Character::LevelUp()
{
	level++;
	exp -= nextExp;
	nextExp += 10;

	maxHP += 5;
	attackPower += 2;
	maxMP += 3;

	std::cout << "レベルアップ\n";
	std::cout << "レベル" << level << "になった！\n";
}


void Character::FullHeal()
{
	hp = maxHP;
}

int Character::GetMP() const
{
	return mp;
}

void Character::UseMP(int amount)
{
	mp -= amount;
	if (mp < 0)  mp = 0;

}

void Character::RecoverMP(int amount)
{
	mp += amount;
	if (mp > maxMP) mp = maxMP;
}

void Character::RecoverHP(int amount)
{
	hp += amount;
	if (mp > maxHP) hp = maxHP;
}