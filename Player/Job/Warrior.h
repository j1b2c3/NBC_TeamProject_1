#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Warrior : public Player
{
public:
	Warrior(string nickname);

	int Attack(Monster& monster, string& action_str) override;
};
