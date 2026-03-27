#pragma once
#include "../Player/player.h"

class Archer : public Player{
public:
    Archer(const std::string& nickname);
    void attack() override;
    void attack(Monster* monster) override;
};