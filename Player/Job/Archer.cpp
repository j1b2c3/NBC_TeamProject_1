#include "Archer.h"

#include <algorithm>
#include "../Player/Player.h"

Archer::Archer(string nickname) : Player(nickname)
{
    jobname = "Archer";
    maxHP = 100;
    curHP = 100;
    atk = 40;
    def = 10;
    dodge = 15;
}

int Archer::Attack(Monster& monster, string& action_str)
{
    int damage = calculateDamage(atk, monster.getDef());
    action_str = "";
    int range = damage / 5;

    if (range <= 0) range = 1;
    int ad = rand() % range;
    damage = damage + ad;

    return monster.TakeDamage(damage, false);
}

void Archer::level_Up()
{
    level++;
    maxHP += 100;
    curHP += 100;
    atk += 26;
    def += 7;
}
