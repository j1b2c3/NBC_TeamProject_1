#pragma once
#include <string>

#include "../Monster/monster.h"

class Monster;

// 임시 Plater
class Player
{
private:
    std::string name;
    int level;
    int exp;
    int hp;
    int hp_max;
    int atk;
    int def;
    int gold;
public:
    Player(std::string name)
        : name(name), level(1), exp(0), hp_max(200), atk(30), def(0), gold(0) 
    {
        Init();
    }
    void Init()
    {
        level = 1;
        exp = 0;
        hp_max = hp = 200;
        atk = 30;
        def = 0;
        gold = 0;
    }

    int Attack(Monster* monster);

    std::string GetName() { return name; }
    int GetLevel() const { return level; }
    int GetExp() const { return exp; }
    int GetHP() const { return hp; }
    int GetHP_MAX() const { return hp_max; }
    int GetATK() const { return atk; }
    int GetDEF() const { return def; }
    int GetGold() const { return gold; }

    void SetHP(int value);
};