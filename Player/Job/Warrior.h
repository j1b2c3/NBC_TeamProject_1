#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Warrior : public Player
{
public:
	Warrior(string nickname);

	int Attack(Monster& monster) override;
	void level_Up() override;
};

