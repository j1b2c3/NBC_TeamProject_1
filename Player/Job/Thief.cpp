#include "Thief.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname)
{
    jobname = "Thief";
    maxHP = 70;
    curHP = 70;
    atk = 15;
    def = 5;
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

void Thief::level_Up()
{
    level++;
    maxHP += 12;
    curHP += 12;
    atk += 3;
    def += 4;
}
