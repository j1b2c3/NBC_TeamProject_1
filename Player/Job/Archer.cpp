#include "Archer.h"
#include "../Player/Player.h"

Archer::Archer(string nickname) : Player(nickname)
{
    jobname = nickname;
    maxHP = (level * 10) + 100;
    curHP = (level * 10) + 100;
    atk = (level * 2)+ 13;
    def = (level * 1) + 10;
    dodge = 15;
}

int Archer::Attack(Monster& monster)
{
    int damage = calculateDamage(atk, monster.getDef());
    // 최소 5 대미지
    if (damage < 5) damage = 5;

    monster.TakeDamage(damage, false);
    return damage;
}
