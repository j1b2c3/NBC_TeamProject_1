#include "Archer.h"
#include "../Player/Player.h"

Archer::Archer(string nickname) : Player(nickname)
{
	jobname = nickname;
	maxHp = 100;
	curHp = 100;
	atk = 7;
	def = 10;
	dodge = 5;
}

void Archer::Attack(Monster& monster)
{
	int damage = calculateDamage(atk, monster.GetDef());
	if (damage < 0) damage = 0;

	monster.TakeDamage(damage, false);
}
