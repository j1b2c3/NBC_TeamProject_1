<<<<<<< HEAD
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string nickname)
{
	level = 1;
	exp = 0;
	maxHp = 100;
	curHp = 100;
	atk = 5;
	def = 10;
	dodge = 5;
	gold = 0;
	this->nickname = nickname;
}

bool Player::isDodged(int dodge)
{
	return rand() % 100 < dodge;
}

int Player::calculateDamage(int atk, int def)
{
	float reduction = def / 100.0f;
	float damage = atk * (1.0f - reduction);

	if (damage < 0) damage = 0;

	return static_cast<int>(damage);
}

void Player::TakeDamage(int damage)
{
	if (isDodged(dodge))
	{
		cout << "플레이어가 공격을 회피했습니다!" << '\n';
	}
	curHp -= damage;
	if (curHp <= 0)
	{
		cout << "사망했습니다!" << '\n';
		cout << "게임 패배" << '\n';
	}
}

void Player::AddExp(int gainedExp)
{
    int needExp = 100;

    for (int i = 1; i < level; i++)
    {
        needExp *= 2;
    }

    exp += gainedExp;

    while (exp >= needExp)
    {
        exp -= needExp;
        level++;
        needExp *= 2;
    }

    cout << "레벨: " << level << '\n';
    cout << "남은 경험치: " << exp << " / " << needExp << '\n';
}

void Player::SubExp(int lostExp)
{
	exp -= lostExp;
	if (exp < 0) exp = 0;
}

void Player::AddGold(int gold)
{
	this->gold += gold;
}

void Player::SubGold(int gold)
{
	this->gold -= gold;
}

string Player::GetNickname()
{
	return nickname;
}

string Player::GetJobName()
{
	return jobname;
}

int Player::GetLevel()
{
	return level;
}

int Player::GetExp()
{
	return exp;
}

float Player::GetMaxHp()
{
	return maxHp;
}

float Player::GetCurHp()
{
	return curHp;
}

int Player::GetAtk()
{
	return atk;
}

int Player::GetDef()
{
	return def;
}

int Player::GetDodge()
{
	return dodge;
}

int Player::GetGold()
{
	return gold;
}

void Player::SetNickname(string nickname)
{
	this->nickname = nickname;
}

void Player::SetLevel(int level)
{
	this->level = level;
}

void Player::SetExp(int exp)
{
	this->exp = exp;
}

void Player::SetMaxHp(float maxHp)
{
	this->maxHp = maxHp;
}

void Player::SetCurHp(float curHp)
{
	this->curHp = curHp;
}

void Player::SetAtk(int atk)
{
	this->atk = atk;
}

void Player::SetDef(int def)
{
	this->def = def;
}

void Player::SetDodge(int dodge)
{
	this->dodge = dodge;
}

void Player::SetGold(int gold)
{
	this->gold = gold;
}
=======
﻿#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string nickname)
{
	level = 1;
	exp = 0;
	maxHp = curHp = 100;
	atk = 5;
	def = 10;
	dodge = 5;
	gold = 0;
	this->nickname = nickname;
}

Player::~Player()
{
	
}

bool Player::isDodged(int dodge)
{
	return rand() % 100 < dodge;
}

int Player::calculateDamage(int atk, int def)
{
	float reduction = def / 100.0f;
	float damage = atk * (1.0f - reduction);

	if (damage < 0) damage = 0;

	return static_cast<int>(damage);
}

int Player::TakeDamage(int damage)
{
	if (isDodged(dodge))
		return -1;

	curHp -= damage;
	if (curHp < 0)
		curHp = 0;
	return damage;
}

void Player::addexp(int gainedExp)
{
    int needExp = 100;

    for (int i = 1; i < level; i++)
    {
        needExp *= 2;
    }

    exp += gainedExp;

    while (exp >= needExp)
    {
        exp -= needExp;
        level++;
        needExp *= 2;
    }

    cout << "레벨: " << level << '\n';
    cout << "남은 경험치: " << exp << " / " << needExp << '\n';
}

void Player::subExp(int lostExp)
{
	exp -= lostExp;
	if (exp < 0) exp = 0;
}

void Player::addGold(int gold)
{
	this->gold += gold;
}

void Player::subGold(int gold)
{
	this->gold -= gold;
}

string Player::getNickname()
{
	return nickname;
}

string Player::getJobName()
{
	return jobname;
}

int Player::getLevel()
{
	return level;
}

int Player::getExp()
{
	return exp;
}

int Player::getMaxHP()
{
	return maxHp;
}

int Player::getCurHP()
{
	return curHp;
}

int Player::getAtk()
{
	return atk;
}

int Player::getDef()
{
	return def;
}

int Player::getDodge()
{
	return dodge;
}

int Player::getGold()
{
	return gold;
}

void Player::setNickname(string nickname)
{
	this->nickname = nickname;
}

void Player::setLevel(int level)
{
	this->level = level;
}

void Player::setExp(int exp)
{
	this->exp = exp;
}

void Player::setMaxHP(float maxHp)
{
	this->maxHp = maxHp;
}

void Player::setCurHP(float curHp)
{
	this->curHp = curHp;
}

void Player::setAtk(int atk)
{
	this->atk = atk;
}

void Player::getDef(int def)
{
	this->def = def;
}

void Player::setdodge(int dodge)
{
	this->dodge = dodge;
}

void Player::setgold(int gold)
{
	this->gold = gold;
}
>>>>>>> Dev
