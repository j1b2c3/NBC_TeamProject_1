#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Thief : public Player
{
public:
	Thief(string nickname);

	int Attack(Monster& monster, string& action_str) override;
};
