#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Thief : public Player
{
public:
	Thief(string nickname);

	void Attack(Monster& monster) override;
};

