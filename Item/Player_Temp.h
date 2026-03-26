#pragma once
#include <string>

// 임시 Plater
class Player
{
public:
    std::string name;
    int hp;
    int maxHP;
    int attack;
    int defense;
    int gold;
    
    Player(std::string name)
        : name(name), hp(200), maxHP(200), attack(30), defense(0), gold(0) {}
};