#include "Thief.h"
#include "../Player/Player.h"
#include <algorithm>
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname)
{
    jobname = "Thief";
    maxHP = 70;
    curHP = 70;
    atk = 25;
    def = 5;
    dodge = 30;
}

int Thief::Attack(Monster& monster, string& action_str)
{
    int damage = calculateDamage(atk, monster.getDef());
    damage = std::max(damage, 0);

    // 크리티컬 (30%)
    if (rand() % 100 < 50)
    {
        action_str = "1.5배의 크리티컬!";
        damage *= 1.5;
    }
    else
    {
        action_str = "";
    }

    return monster.TakeDamage(damage, true);
}

void Thief::level_Up()
{
    level++;
    maxHP += 120;
    curHP += 120;
    atk += 26;
    def += 7;
}
