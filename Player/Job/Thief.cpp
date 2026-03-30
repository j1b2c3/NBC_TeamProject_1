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

int Thief::Attack(Monster& monster, string& action_str)
{
    int damage = calculateDamage(atk, monster.getDef());
    if (damage < 0) damage = 0;

    // 크리티컬 (30%)
    if (rand() % 100 < 50)
    {
        action_str = "1.5배의 크리티컬!";
        damage *= 1.5f;
    }
    else
    {
        action_str = "";
    }

    monster.TakeDamage(damage, true);
    return damage;
}
