#include "Mage.h"
#include "../Player/Player.h"

Mage::Mage(string nickname) : Player(nickname)
{
	jobname = nickname;
	maxHp = 85;
	curHp = 85;
	atk = 10;
	def = 10;
	dodge = 5;
}

int Mage::Attack(Monster& monster)
{
	int damage = atk;

	return monster.TakeDamage(damage, true);
}
