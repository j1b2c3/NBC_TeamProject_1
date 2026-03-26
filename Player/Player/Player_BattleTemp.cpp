#include "Player_BattleTemp.h"

int Player::Attack(Monster* monster)
{
	int damage = atk - monster->getDefence();
	if (damage <= 0)
		damage = 1;
	monster->setHP(monster->getHP() - damage);
	return damage;
}

void Player::SetHP(int value)
{
	hp = value;
	if (hp < 0)
		hp = 0;
	else if (hp > hp_max)
		hp = hp_max;
}
