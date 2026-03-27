#include "Warrior.h"
#include "../Player/Player.h"

Warrior::Warrior(string nickname) : Player(nickname)
{
	jobname = "전사";
	maxHp = 120;
	curHp = 120;
	atk = 3;
	def = 20;
	dodge = 5;
}

void Warrior::Attack(Monster& monster)
{
	int damage = calculateDamage(atk, monster.GetDef());
	if (damage < 0) damage = 0;

	monster.TakeDamage(damage, true);
}
