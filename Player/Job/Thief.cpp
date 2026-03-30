<<<<<<< HEAD
#include "Thief.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname)
{
	jobname = nickname;
	maxHp = 70;
	curHp = 70;
	atk = 15;
	def = 5;
	dodge = 20;
}

void Thief::Attack(Monster& monster)
{
    int damage = calculateDamage(atk, monster.GetDef());
    if (damage < 0) damage = 0;

    // 크리티컬 (30%)
    if (rand() % 100 < 30)
    {
        damage *= 1.5;
        cout << "크리티컬!" << '\n';
    }

    monster.TakeDamage(damage, true);
}
=======
﻿#include "Thief.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname)
{
	jobname = "도적";
	maxHp = 70;
	curHp = 70;
	atk = 15;
	def = 5;
	dodge = 20;
}

int Thief::Attack(Monster& monster)
{
    int damage = calculateDamage(atk, monster.GetDef());
    if (damage < 0) damage = 0;

    // 크리티컬 (30%)
    if (rand() % 100 < 30)
    {
        damage *= 1.5;
        cout << "크리티컬!" << '\n';
    }

    return monster.TakeDamage(damage, true);
}
>>>>>>> Dev
