#include "Warrior.h"
#include "../Player/Player.h"

Warrior::Warrior(string nickname) : Player(nickname)
{
    jobname = "Warrior";
    maxHP = 120;
    curHP = 120;
    atk = 45;
    def = 25;
    dodge = 5;
}

int Warrior::Attack(Monster& monster, string& action_str)
{
    int damage = calculateDamage(atk, monster.getDef());
    if (damage < 0) damage = 0;

    action_str = "";
    return monster.TakeDamage(damage, true);
}

void Warrior::level_Up()
{
    level++;
    maxHP += 120;
    curHP += 120;
    atk += 40;
    def += 10;
}
