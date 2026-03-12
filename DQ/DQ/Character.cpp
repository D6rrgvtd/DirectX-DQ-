#include "Character.h"

Character::Character(const std::string&, int hp, int attack, int speed,int keke,int maey,int def)
{
	this->name = name;
	this->maxHP = hp;
	this->hp = hp;
	this->attackPower = attack;
	this->speed = speed;
	this->keikentu = keke;
	this->maney = maey;
	this->defense = def;

	gold = 20;
	maxMP = 10;
	mp = maxMP;

	level = 1;
	exp = 0;
	nextExp = 10,12;
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

int Character::Getdefence() const
{
	return defense;
}

int Character::HaveGold() const
{
	return gold;
}

int Character::GetGold() const
{
	return maney;
}
int Character::GetExp() const
{
	return exp;
}

void Character::AddGold(int amount)
{
	gold += maney;
	std::cout << maney << "ゴールド獲得\n";
	if (gold < 0)
		gold = 0;
}

void Character::AddAttack(int amount)
{
	attackPower += amount;
}

void Character::Adddefence(int amount)
{
	defense += amount;
}

void Character::AddExp(int amount)
{
	exp += keikentu;
	std::cout <<keikentu<< "の経験値を獲得\n";

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
	defense += 1;

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
void Character::SetHP(int value)
{
	hp = value;
}
void Character::SetMP(int value)
{
	mp = value;
}

void Character::SetGold(int value)
{
	gold = value;
}

void Character::SetExp(int value)
{
	exp = value;
}