#pragma once
#include "../Player/player.h"

class Magician : public Player{
public:
    Magician(const string& nickname);
    void attack() override;
    void attack(Monster* monster) override;
};