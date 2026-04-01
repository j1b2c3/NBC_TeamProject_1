#include "Monster.h"
#include "../Player/Player.h"
#include <algorithm>
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
    this->specialMessage = "";
}

bool Monster::isDodged(int dodge)
{
    return rand() % 100 < dodge;
}

int Monster::calculateDamage(int atk, int def, bool is_defence)
{
    int damage = atk * (100.0f / (100.0f + def));
    if (is_defence) damage /= 2;
    
    if (damage <= 0)
        damage = is_defence ? 0 : 1;

    return damage;
}

int Monster::attack(Player& player, bool is_defence, string& action_str)
{
    if (specialMessage.empty())
        return player.TakeDamage(calculateDamage(atk, player.getDef(), is_defence));
    else
        return 0;
}

int Monster::TakeDamage(int damage, bool canDodge)
{
    if (isDodged(dodge))
        return -1;

    curHP -= damage;
    curHP = std::max(curHP, 0);
    return damage;
}

inline int getRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void Monster::giveLoot(Player& player, int& outEXP, int& outGOLD)
{
    int exp = getRandom(minExp, maxExp);
    outEXP = exp;
    //player.addexp(exp);   // BattleSystem에서 처리

    int gold = getRandom(minGold, maxGold);
    outGOLD = gold;
    //player.addGold(gold); // BattleSystem에서 처리
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

std::string Monster::getSpecialMessage()
{
    return specialMessage;
}

void Monster::ClearSpecialMessage()
{
    specialMessage.clear();
}
