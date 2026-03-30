#include "Archer.h"
#include "../Player/Player.h"

Archer::Archer(string nickname) : Player(nickname)
{
    jobname = "Archer";
    maxHP = 100;
    curHP = 100;
    atk = 13;
    def = 10;
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

void Archer::level_Up()
{
    level++;
    maxHP += 10;
    curHP += 10;
    atk += 2;
    def += 1;
}