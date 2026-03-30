#include "Thief.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname)
{
    jobname = nickname;
    maxHP = (level * 10) + 70;
    curHP = (level * 10) + 70;
    atk = (level * 2) + 15;
    def = (level * 1) + 5;
    dodge = 30;
}

int Thief::Attack(Monster& monster)
{
    int damage = calculateDamage(atk, monster.getDef());
    if (damage < 0) damage = 0;

    // 크리티컬 (30%)
    if (rand() % 100 < 50)
    {
        damage *= 1.5;
    }

    monster.TakeDamage(damage, true);
    return damage;
}
