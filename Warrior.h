#pragma once
#include "Player.h"
#include <string>
using namespace std;

class Warrior : public Player
{
public:
	Warrior(string nickname);

	void Attack(Monster& monster) override;
};

