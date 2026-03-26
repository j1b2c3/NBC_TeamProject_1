#pragma once
#include <string>

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

    int GetLevel() { return level; }
    int GetExp() { return exp; }
    int GetHP() { return hp; }
    int GetMaxHP() { return hp_max; }
    int GetATK() { return atk; }
    int GetDEF() { return def; }
    int GetGold() { return gold; }
};