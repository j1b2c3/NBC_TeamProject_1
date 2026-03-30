#include "Archer.h"
#include "../Player/Player.h"

Archer::Archer(string nickname) : Player(nickname)
{
	jobname = nickname;
	maxHP = 100;
	curHP = 100;
	atk = 7;
	def = 10;
	dodge = 5;
}

int Archer::Attack(Monster& monster)
{
	int damage = calculateDamage(atk, monster.getDef());
	if (damage < 0) damage = 0;

	monster.TakeDamage(damage, false);
	return damage;
}
