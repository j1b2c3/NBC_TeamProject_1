#include "Mage.h"
#include "../Player/Player.h"

Mage::Mage(string nickname) : Player(nickname)
{
    jobname = "마법사";
    maxHP = 85;
    curHP = 85;
    atk = 25;
    def = 10;
    dodge = 5;
}

int Mage::Attack(Monster& monster)
{
    int damage = atk;
    // 10프로 확률로 대미지 2배
    if (rand() % 100 < 10)
    {
        damage *= 2;
    }
    monster.TakeDamage(damage, true);

    return damage;
}
