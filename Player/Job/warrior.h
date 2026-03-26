#pragma once
#include "../Player/player.h"

class Warrior : public Player{
public:
    Warrior(const string& nickname);
    void attack() override;
    void attack(Monster* monster) override;

};