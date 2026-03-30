#include "Monster.h"
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
	this->maxHP = this->curHP = Hp;
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

int Monster::attack(Player& player)
{
	int damage = calculateDamage(atk, player.getDef());
	if (damage < 0) damage = 1;

	player.TakeDamage(damage);
	
	return damage;
}

void Monster::TakeDamage(int damage, bool canDodge)
{
	if (isDodged(dodge))
	{
		cout << "몬스터가 공격을 회피했습니다!" << '\n';
	}
	curHP -= damage;
	if (curHP <= 0)
	{
		curHP = 0;
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
	player.addexp(exp);
	int gold = getRandom(minGold, maxGold);
	player.addGold(gold);
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
	return maxHP;
}

int Monster::getCurHP()
{
	return curHP;
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
}
