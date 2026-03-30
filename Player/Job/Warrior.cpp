#include "Warrior.h"
#include "../Player/Player.h"

Warrior::Warrior(string nickname) : Player(nickname)
{
    jobname = nickname;
    maxHP = 120;
    curHP = 120;
    atk = 15;
    def = 25;
    dodge = 5;
}

int Warrior::Attack(Monster& monster)
{
    int damage = calculateDamage(atk, monster.getDef());
    if (damage < 0) damage = 0;
    monster.TakeDamage(damage, true);
    return damage;
}
