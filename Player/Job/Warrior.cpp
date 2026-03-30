#include "Warrior.h"
#include "../Player/Player.h"

Warrior::Warrior(string nickname) : Player(nickname)
{
    jobname = nickname;
    maxHP = (level * 12) + 120;
    curHP = (level * 12) + 120;
    atk = (level * 3) + 15;
    def = (level * 4) + 25;
    dodge = 5;
}

int Warrior::Attack(Monster& monster, string& action_str)
{
    int damage = calculateDamage(atk, monster.getDef());
    if (damage < 0) damage = 0;

    action_str = "";
    monster.TakeDamage(damage, true);
    return damage;
}
