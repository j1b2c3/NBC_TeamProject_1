#include "Monster.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;

Monster::Monster(
    string name,
    int level,
    int Hp,
    int atk,
    int def,
    int dodge,
    int minExp,
    int maxExp,
    int minGold,
    int maxGold
)
{
    this->name = name;
    this->level = level;
    this->maxHP = this->curHP = Hp;
    this->atk = atk;
    this->def = def;
    this->dodge = dodge;
    this->minExp = minExp;
    this->maxExp = maxExp;
    this->minGold = minGold;
    this->maxGold = maxGold;
}

bool Monster::isDodged(int dodge)
{
    return rand() % 100 < dodge;
}

int Monster::calculateDamage(int atk, int def, bool is_defence)
{
    if (is_defence) def *= 2;
    float reduction = def / 100.0f;
    int damage = static_cast<int>((float)atk * (1.0f - reduction));

    if (damage <= 0)
        damage = is_defence ? 0 : 1;

    return damage;
}

int Monster::attack(Player& player, bool is_defence)
{
    return player.TakeDamage(calculateDamage(atk, player.getDef(), is_defence));
}

int Monster::TakeDamage(int damage, bool canDodge)
{
    if (isDodged(dodge))
        return -1;

    curHP -= damage;
    if (curHP < 0)
        curHP = 0;
    return damage;
}

inline int getRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void Monster::giveLoot(Player& player)
{
    int exp = getRandom(minExp, maxExp);
    player.addexp(exp);
    int gold = getRandom(minGold, maxGold);
    player.addGold(gold);
}

string Monster::getName()
{
    return name;
}

int Monster::getLevel()
{
    return level;
}

int Monster::getMaxHP()
{
    return maxHP;
}

int Monster::getCurHP()
{
    return curHP;
}

int Monster::getAtk()
{
    return atk;
}

int Monster::getDef()
{
    return def;
}

int Monster::getDodge()
{
    return dodge;
}

int Monster::getMaxExp()
{
    return maxExp;
}

int Monster::getMinExp()
{
    return minExp;
}

int Monster::getMaxGold()
{
    return maxGold;
}

int Monster::getMinGold()
{
    return minGold;
}
