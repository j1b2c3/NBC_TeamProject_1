#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Thief : public Player
{
public:
	Thief(string nickname);

	void level_Up() override;
	int Attack(Monster& monster, string& action_str) override;
};

