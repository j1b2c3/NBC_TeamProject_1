#include "Mage.h"
#include "../Player/Player.h"

Mage::Mage(string nickname) : Player(nickname)
{
    jobname = "Mage";
    maxHP = 85;
    curHP = 85;
    atk = 25;
    def = 10;
    dodge = 5;
}

int Mage::Attack(Monster& monster, string& action_str)
{
    int damage = atk;
    // 10프로 확률로 대미지 2배
    if (rand() % 100 < 10)
    {
        action_str = "2배의 크리티컬!";
        damage *= 2.0f;
    }
    monster.TakeDamage(damage, true);

    return damage;
}

void Mage::level_Up()
{
    level++;
    maxHP += 8;
    curHP += 8;
    atk += 3;
    def += 2;
}