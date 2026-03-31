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
    // 최소 5 대미지
    damage = std::max(damage, 5);
    action_str = "";
    return monster.TakeDamage(damage, false);
}

void Archer::level_Up()
{
    level++;
    maxHP += 100;
    curHP += 100;
    atk += 25;
    def += 7;
}
