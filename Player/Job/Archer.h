<<<<<<< HEAD
#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Archer : public Player
{
public:
	Archer(string nickname);

	void Attack(Monster& monster) override;
=======
﻿#pragma once
#include "../Player/Player.h"
#include <string>
using namespace std;

class Archer : public Player
{
public:
	Archer(string nickname);

	int Attack(Monster& monster) override;
>>>>>>> Dev
};