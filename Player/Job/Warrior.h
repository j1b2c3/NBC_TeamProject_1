<<<<<<< HEAD
#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Warrior : public Player
{
public:
	Warrior(string nickname);

	void Attack(Monster& monster) override;
};

=======
﻿#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Warrior : public Player
{
public:
	Warrior(string nickname);

	int Attack(Monster& monster) override;
};

>>>>>>> Dev
