<<<<<<< HEAD
﻿#include "Monster.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;

Monster::Monster(
	string name,
	int level,
	int Hp,
	int atk,
	int def,
	int dodge,
	int minExp,
	int maxExp,
	int minGold,
	int maxGold
)
{
	this->name = name;
	this->level = level;
	this->maxHp = this->curHp = Hp;
	this->atk = atk;
	this->def = def;
	this->dodge = dodge;
	this->minExp = minExp;
	this->maxExp = maxExp;
	this->minGold = minGold;
	this->maxGold = maxGold;
}

Monster::~Monster()
{
	
}

bool Monster::isDodged(int dodge)
{
	return rand() % 100 < dodge;
}

int Monster::calculateDamage(int atk, int def)
{
	float reduction = def / 100.0f;
	float damage = atk * (1.0f - reduction);

	if (damage < 0) damage = 0;

	return static_cast<int>(damage);
}

int Monster::Attack(Player& player)
{
	int damage = calculateDamage(atk, player.getDef());
	if (damage < 0) damage = 0;

	return player.TakeDamage(damage);
}

int Monster::TakeDamage(size_t damage, bool canDodge)
{
	if (isDodged(dodge))
		return -1;

	curHp -= damage;
	if (curHp < 0)
		curHp = 0;
	return damage;
}

inline int getRandom(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Monster::giveLoot(Player& player)
{
	int exp = getRandom(minExp, maxExp);
	player.addexp(exp);
	int gold = getRandom(minGold, maxGold);
	player.subGold(gold);
}

string Monster::getName()
{
	return name;
}

int Monster::getLevel()
{
	return level;
}

int Monster::getMaxHP()
{
	return maxHp;
}

int Monster::getCurHP()
{
	return curHp;
}

int Monster::getAtk()
{
	return atk;
}

int Monster::getDef()
{
	return def;
}

int Monster::getDodge()
{
	return dodge;
}

int Monster::getMaxExp()
{
	return maxExp;
}

int Monster::getMinExp()
{
	return minExp;
}

int Monster::getMaxGold()
{
	return maxGold;
}

int Monster::getMinGold()
{
	return minGold;
=======
﻿<<<<<<< HEAD
﻿#include "Monster.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;

Monster::Monster(
	string name,
	int level,
	float maxHp,
	float curHp,
	int atk,
	int def,
	int dodge,
	int minExp,
	int maxExp,
	int minGold,
	int maxGold
)
{
	this->name = name;
	this->level = level;
	this->maxHp = maxHp;
	this->curHp = curHp;
	this->atk = atk;
	this->def = def;
	this->dodge = dodge;
	this->minExp = minExp;
	this->maxExp = maxExp;
	this->minGold = minGold;
	this->maxGold = maxGold;
}

bool Monster::isDodged(int dodge)
{
	return rand() % 100 < dodge;
}

int Monster::calculateDamage(int atk, int def)
{
	float reduction = def / 100.0f;
	float damage = atk * (1.0f - reduction);

	if (damage < 0) damage = 0;

	return static_cast<int>(damage);
}

void Monster::Attack(Player& player)
{
	int damage = calculateDamage(atk, player.GetDef());
	if (damage < 0) damage = 0;

	player.TakeDamage(damage);
}

void Monster::TakeDamage(int damage, bool canDodge)
{
	if (isDodged(dodge))
	{
		cout << "몬스터가 공격을 회피했습니다!" << '\n';
	}
	curHp -= damage;
	if (curHp <= 0)
	{
		curHp = 0;
		cout << "몬스터를 처치했습니다!" << '\n';
	}
}

inline int getRandom(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Monster::giveLoot(Player& player)
{
	int exp = getRandom(minExp, maxExp);
	player.AddExp(exp);
	int gold = getRandom(minGold, maxGold);
	player.SubGold(gold);
}

string Monster::GetName()
{
	return name;
}

int Monster::GetLevel()
{
	return level;
}

float Monster::GetMaxHp()
{
	return maxHp;
}

float Monster::GetCurHp()
{
	return curHp;
}

int Monster::GetAtk()
{
	return atk;
}

int Monster::GetDef()
{
	return def;
}

int Monster::GetDodge()
{
	return dodge;
}

int Monster::GetMaxExp()
{
	return maxExp;
}

int Monster::GetMinExp()
{
	return minExp;
}

int Monster::GetMaxGold()
{
	return maxGold;
}

int Monster::GetMinGold()
{
	return minGold;
=======
﻿#include "Monster.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;

Monster::Monster(
	string name,
	int level,
	int Hp,
	int atk,
	int def,
	int dodge,
	int minExp,
	int maxExp,
	int minGold,
	int maxGold
)
{
	this->name = name;
	this->level = level;
	this->maxHp = this->curHp = Hp;
	this->atk = atk;
	this->def = def;
	this->dodge = dodge;
	this->minExp = minExp;
	this->maxExp = maxExp;
	this->minGold = minGold;
	this->maxGold = maxGold;
}

bool Monster::isDodged(int dodge)
{
	return rand() % 100 < dodge;
}

int Monster::calculateDamage(int atk, int def)
{
	float reduction = def / 100.0f;
	float damage = atk * (1.0f - reduction);

	if (damage < 0) damage = 0;

	return static_cast<int>(damage);
}

int Monster::Attack(Player& player)
{
	int damage = calculateDamage(atk, player.GetDef());
	if (damage < 0) damage = 0;

	return player.TakeDamage(damage);
}

int Monster::TakeDamage(size_t damage, bool canDodge)
{
	if (isDodged(dodge))
		return -1;

	curHp -= damage;
	if (curHp < 0)
		curHp = 0;
	return damage;
}

inline int getRandom(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Monster::giveLoot(Player& player)
{
	int exp = getRandom(minExp, maxExp);
	player.AddExp(exp);
	int gold = getRandom(minGold, maxGold);
	player.SubGold(gold);
}

string Monster::GetName()
{
	return name;
}

int Monster::GetLevel()
{
	return level;
}

int Monster::GetMaxHp()
{
	return maxHp;
}

int Monster::GetCurHp()
{
	return curHp;
}

int Monster::GetAtk()
{
	return atk;
}

int Monster::GetDef()
{
	return def;
}

int Monster::GetDodge()
{
	return dodge;
}

int Monster::GetMaxExp()
{
	return maxExp;
}

int Monster::GetMinExp()
{
	return minExp;
}

int Monster::GetMaxGold()
{
	return maxGold;
}

int Monster::GetMinGold()
{
	return minGold;
>>>>>>> Dev
>>>>>>> BattleBranch
}