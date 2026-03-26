#pragma once
#include "../Player/player.h"

class Warrior : public Player{
public:
    Warrior(string nickname);
    void attack() override;
    void attack(Monster* monster) override;

};