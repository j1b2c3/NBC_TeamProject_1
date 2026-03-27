#include "Monster.h"
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
		cout << "몬스터가 공격을 회피했습니다!" << endl;
	}
	curHp -= damage;
	if (curHp <= 0)
	{
		curHp = 0;
		cout << "몬스터를 처치했습니다!" << endl;
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
}