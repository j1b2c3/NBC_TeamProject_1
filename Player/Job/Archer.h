#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Archer : public Player
{
public:
	Archer(string nickname);

	int Attack(Monster& monster, string& action_str) override;
};
