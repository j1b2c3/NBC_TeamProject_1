#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Mage : public Player
{
public:
    Mage(string nickname);

    void Attack(Monster& monster) override;
};