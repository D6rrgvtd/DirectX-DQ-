#include "Character.h"

Character::Character(const std::string&, int hp, int atk)
	: name(name),hp(hp),attack(atk)
{
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
	return attack;
}