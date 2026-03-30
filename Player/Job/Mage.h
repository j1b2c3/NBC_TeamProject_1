#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Mage : public Player
{
public:
    Mage(string nickname);

    int Attack(Monster& monster) override;
    void level_Up() override;
};
