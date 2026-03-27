#pragma once
#include "../Player/player.h"

class Thief : public Player{
public:
    Thief(const string& nickname);
    void attack() override;
    void attack(Monster* monster) override;
};