#include "Mage.h"
#include "../Player/Player.h"

Mage::Mage(string nickname) : Player(nickname)
{
    jobname = "마법사";
    maxHP = 85;
    curHP = 85;
    atk = 10;
    def = 10;
    dodge = 5;
}

int Mage::Attack(Monster& monster)
{
    int damage = atk;
    monster.TakeDamage(damage, true);
    return damage;
}
